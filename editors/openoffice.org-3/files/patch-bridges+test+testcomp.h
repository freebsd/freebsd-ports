--- ../bridges/test/testcomp.h.orig	Wed Mar 12 10:06:16 2003
+++ ../bridges/test/testcomp.h	Wed Mar 12 10:05:54 2003
@@ -2,9 +2,9 @@
  *
  *  $RCSfile: testcomp.h,v $
  *
- *  $Revision: 1.2 $
+ *  $Revision: 1.4 $
  *
- *  last change: $Author: jbu $ $Date: 2001/03/16 09:42:20 $
+ *  last change: $Author: jbu $ $Date: 2002/04/18 10:09:22 $
  *
  *  The Contents of this file are made available subject to the terms of
  *  either of the following licenses
@@ -87,9 +87,9 @@
 
 public:	
 	// XInterface
-	Any	SAL_CALL queryInterface( const com::sun::star::uno::Type & aType);
-	void 		SAL_CALL acquire() 						 { OWeakObject::acquire(); }
-	void 		SAL_CALL release() 						 { OWeakObject::release(); }
+	Any	SAL_CALL queryInterface( const com::sun::star::uno::Type & aType) throw ( ::com::sun::star::uno::RuntimeException );
+	void 		SAL_CALL acquire() throw() 						 { OWeakObject::acquire(); }
+	void 		SAL_CALL release() throw()						 { OWeakObject::release(); }
 
 public:	
     virtual void SAL_CALL setIn( const ::com::sun::star::uno::Reference< ::test::XCallMe >& callback ) throw(::com::sun::star::uno::RuntimeException);
@@ -114,9 +114,9 @@
 
 public:	
 	// XInterface
-	Any	SAL_CALL queryInterface( const com::sun::star::uno::Type & aType);
-	void 		SAL_CALL acquire() 						 { OWeakObject::acquire(); }
-	void 		SAL_CALL release() 						 { OWeakObject::release(); }
+	Any	SAL_CALL queryInterface( const com::sun::star::uno::Type & aType) throw ( ::com::sun::star::uno::RuntimeException );
+	void 		SAL_CALL acquire()throw() 						 { OWeakObject::acquire(); }
+	void 		SAL_CALL release()throw() 						 { OWeakObject::release(); }
 public:
 	// XCallMe
     virtual void SAL_CALL call( const ::rtl::OUString& s, sal_Int32 nToDo )
@@ -150,9 +150,9 @@
 
 public:	
 	// XInterface
-	Any	        SAL_CALL queryInterface( const  com::sun::star::uno::Type & aType );
-	void 		SAL_CALL acquire() 						 { OWeakObject::acquire(); }
-	void 		SAL_CALL release() 						 { OWeakObject::release(); }
+	Any	        SAL_CALL queryInterface( const  com::sun::star::uno::Type & aType ) throw ( ::com::sun::star::uno::RuntimeException );
+	void 		SAL_CALL acquire()throw() 						 { OWeakObject::acquire(); }
+	void 		SAL_CALL release() throw()						 { OWeakObject::release(); }
 public:
 	virtual ::com::sun::star::uno::Reference< ::test::XCallMe > SAL_CALL createCallMe(  )
 		throw(::com::sun::star::uno::RuntimeException);
@@ -161,28 +161,6 @@
 
 };
 
-/*
-class OConnectCallback :
-	public ::cppu::OWeakObject,
-	public XConnectCallback
-{
-public:
-	OConnectCallback( ){}
-	~OConnectCallback(){ printf( "callback dies\n" );}
-public:	
-	// XInterface
-	Any	        SAL_CALL queryInterface( const Type & aType);
-	void 		SAL_CALL acquire() 						 { OWeakObject::acquire(); }
-	void 		SAL_CALL release() 						 { OWeakObject::release(); }
-
-public:
-	// XConnectCallback
-    virtual void SAL_CALL attemptConnect(
-		const Reference< XConnectionServerSide >& connection )
-		throw(SecurityException, RuntimeException);
-};
-
-*/
 
 class OInstanceProvider :
 	public ::cppu::OWeakObject,
@@ -196,12 +174,11 @@
 	~OInstanceProvider(){ printf( "instance provider dies\n" );}
 public:	
 	// XInterface
-	Any	        SAL_CALL queryInterface( const Type & aType);
-	void 		SAL_CALL acquire() 						 { OWeakObject::acquire(); }
-	void 		SAL_CALL release() 						 { OWeakObject::release(); }
+	Any	        SAL_CALL queryInterface( const Type & aType)throw ( ::com::sun::star::uno::RuntimeException );
+	void 		SAL_CALL acquire()throw() 						 { OWeakObject::acquire(); }
+	void 		SAL_CALL release() throw()						 { OWeakObject::release(); }
 	
 public:
-	// XConnectCallback
     virtual ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface > SAL_CALL
 	       getInstance( const ::rtl::OUString& sObjectName )
 		         throw( ::com::sun::star::container::NoSuchElementException,
