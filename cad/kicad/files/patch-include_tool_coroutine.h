--- include/tool/coroutine.h.orig	2017-07-14 19:17:29 UTC
+++ include/tool/coroutine.h
@@ -27,10 +27,12 @@
 
 #include <cstdlib>
 
-#include <boost/context/fcontext.hpp>
+// Patch obtained from https://git.archlinux.org/svntogit/community.git/tree/trunk/boost-1.61.patch?h=packages/kicad
 #include <boost/version.hpp>
+#include <type_traits>
 
-#include "delegate.h"
+#include <boost/context/execution_context.hpp>
+#include <boost/context/protected_fixedsize_stack.hpp>
 
 /**
  *  Class COROUNTINE.
@@ -53,13 +55,12 @@
  *  See coroutine_example.cpp for sample code.
  */
 
-template <class ReturnType, class ArgType>
+template <typename ReturnType, typename ArgType>
 class COROUTINE
 {
 public:
     COROUTINE() :
-        m_saved( NULL ), m_self( NULL ), m_stack( NULL ), m_stackSize( c_defaultStackSize ),
-        m_running( false )
+	COROUTINE( nullptr )
     {
     }
 
@@ -69,8 +70,7 @@ public:
      */
     template <class T>
     COROUTINE( T* object, ReturnType(T::* ptr)( ArgType ) ) :
-        m_func( object, ptr ), m_self( NULL ), m_saved( NULL ), m_stack( NULL ),
-        m_stackSize( c_defaultStackSize ), m_running( false )
+	COROUTINE( std::bind( ptr, object, std::placeholders::_1 ) )
     {
     }
 
@@ -78,9 +78,11 @@ public:
      * Constructor
      * Creates a coroutine from a delegate object
      */
-    COROUTINE( DELEGATE<ReturnType, ArgType> aEntry ) :
-        m_func( aEntry ), m_saved( NULL ), m_self( NULL ), m_stack( NULL ),
-        m_stackSize( c_defaultStackSize ), m_running( false )
+    COROUTINE( std::function<ReturnType(ArgType)> aEntry ) :
+        m_func( std::move( aEntry ) ),
+        m_running( false ),
+        m_caller( nullptr ),
+        m_callee( nullptr )
     {
         // Avoid not initialized members, and make static analysers quiet
         m_args = 0;
@@ -89,18 +91,13 @@ public:
 
     ~COROUTINE()
     {
-        if( m_saved )
-            delete m_saved;
-
-#if BOOST_VERSION >= 105600
-        if( m_self )
-            delete m_self;
-#endif
-
-        if( m_stack )
-            free( m_stack );
+	delete m_callee;
     }
 
+private:
+    using context_type = boost::context::execution_context<COROUTINE*>;
+
+public:
     /**
      * Function Yield()
      *
@@ -110,7 +107,9 @@ public:
      */
     void Yield()
     {
-        jump( m_self, m_saved, 0 );
+        auto result = (*m_caller)( this );
+        *m_caller = std::move( std::get<0>( result ) );
+
     }
 
     /**
@@ -122,7 +121,7 @@ public:
     void Yield( ReturnType& aRetVal )
     {
         m_retVal = aRetVal;
-        jump( m_self, m_saved, 0 );
+        m_caller( this );
     }
 
     /**
@@ -130,9 +129,9 @@ public:
      *
      * Defines the entry point for the coroutine, if not set in the constructor.
      */
-    void SetEntry( DELEGATE<ReturnType, ArgType> aEntry )
+    void SetEntry( std::function<ReturnType(ArgType)> aEntry )
     {
-        m_func = aEntry;
+	m_func = std::move( aEntry );
     }
 
     /* Function Call()
@@ -143,30 +142,19 @@ public:
      */
     bool Call( ArgType aArgs )
     {
-        // fixme: Clean up stack stuff. Add a guard
-        m_stack = malloc( c_defaultStackSize );
-
-        // align to 16 bytes
-        void* sp = (void*) ( ( ( (ptrdiff_t) m_stack ) + m_stackSize - 0xf ) & ( ~0x0f ) );
-
-        // correct the stack size
-        m_stackSize -= ( (size_t) m_stack + m_stackSize - (size_t) sp );
-
-        assert( m_self == NULL );
-        assert( m_saved == NULL );
+        assert( m_callee == NULL );
+        assert( m_caller == NULL );
 
         m_args = &aArgs;
-#if BOOST_VERSION >= 105600
-        m_self = new boost::context::fcontext_t();
-        *m_self = boost::context::make_fcontext( sp, m_stackSize, callerStub );
-#else
-        m_self = boost::context::make_fcontext( sp, m_stackSize, callerStub );
-#endif
-        m_saved = new boost::context::fcontext_t();
+
+        m_callee = new context_type( std::allocator_arg_t(),
+                    boost::context::protected_fixedsize_stack( c_defaultStackSize ), &COROUTINE::callerStub );
 
         m_running = true;
+
         // off we go!
-        jump( m_saved, m_self, reinterpret_cast<intptr_t>( this ) );
+        auto result = (*m_callee)( this );
+        *m_callee = std::move( std::get<0>( result ) );
         return m_running;
     }
 
@@ -179,7 +167,8 @@ public:
      */
     bool Resume()
     {
-        jump( m_saved, m_self, 0 );
+        auto result = (*m_callee)( this );
+        *m_callee = std::move( std::get<0>( result ) );
 
         return m_running;
     }
@@ -208,61 +197,36 @@ private:
     static const int c_defaultStackSize = 2000000;    // fixme: make configurable
 
     /* real entry point of the coroutine */
-    static void callerStub( intptr_t aData )
+    static context_type callerStub( context_type caller, COROUTINE* cor )
     {
         // get pointer to self
-        COROUTINE<ReturnType, ArgType>* cor = reinterpret_cast<COROUTINE<ReturnType, ArgType>*>( aData );
+        cor->m_caller = &caller;
 
         // call the coroutine method
-        cor->m_retVal = cor->m_func( *cor->m_args );
+        cor->m_retVal = cor->m_func( *( cor->m_args ) );
         cor->m_running = false;
 
         // go back to wherever we came from.
-        jump( cor->m_self, cor->m_saved, 0 );    // reinterpret_cast<intptr_t>( this ));
+        return caller;
     }
 
     ///> Wrapper for jump_fcontext to assure compatibility between different boost versions
-    static inline intptr_t jump(boost::context::fcontext_t* aOld, boost::context::fcontext_t* aNew,
-                                intptr_t aP, bool aPreserveFPU = true )
-    {
-#if BOOST_VERSION >= 105600
-        return boost::context::jump_fcontext( aOld, *aNew, aP, aPreserveFPU );
-#else
-        return boost::context::jump_fcontext( aOld, aNew, aP, aPreserveFPU );
-#endif
-    }
-
-    template <typename T>
-    struct strip_ref
-    {
-        typedef T result;
-    };
 
-    template <typename T>
-    struct strip_ref<T&>
-    {
-        typedef T result;
-    };
+    std::function<ReturnType(ArgType)> m_func;
 
-    DELEGATE<ReturnType, ArgType> m_func;
+    bool m_running;
 
     ///< pointer to coroutine entry arguments. Stripped of references
     ///< to avoid compiler errors.
-    typename strip_ref<ArgType>::result* m_args;
+    typename std::remove_reference<ArgType>::type* m_args;
+
     ReturnType m_retVal;
 
     ///< saved caller context
-    boost::context::fcontext_t* m_saved;
+    context_type* m_caller;
 
     ///< saved coroutine context
-    boost::context::fcontext_t* m_self;
-
-    ///< coroutine stack
-    void* m_stack;
-
-    size_t m_stackSize;
-
-    bool m_running;
+   context_type* m_callee;
 };
 
 #endif
