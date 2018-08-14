--- flow/libs/system/src/error_code.cpp.orig	2018-08-01 01:25:10 UTC
+++ flow/libs/system/src/error_code.cpp
@@ -15,6 +15,7 @@
 // the library is being built (possibly exporting rather than importing code)
 #define BOOST_SYSTEM_SOURCE 
 
+#include <boost/version.hpp>
 #include <boost/system/config.hpp>
 #include <boost/system/error_code.hpp>
 #include <boost/cerrno.hpp>
@@ -37,6 +38,7 @@ using namespace boost::system::errc;
 
 //----------------------------------------------------------------------------//
 
+#if BOOST_VERSION < 106800
 namespace
 {
 #if defined(__PGI)
@@ -48,7 +50,7 @@ namespace
   {
   public:
     generic_error_category(){}
-    const char *   name() const;
+    const char *   name() const BOOST_SYSTEM_NOEXCEPT;
     std::string    message( int ev ) const;
   };
 
@@ -56,14 +58,14 @@ namespace
   {
   public:
     system_error_category(){}
-    const char *        name() const;
+    const char *        name() const BOOST_SYSTEM_NOEXCEPT;
     std::string         message( int ev ) const;
-    error_condition     default_error_condition( int ev ) const;
+    error_condition     default_error_condition( int ev ) const BOOST_SYSTEM_NOEXCEPT;
   };
 
   //  generic_error_category implementation  ---------------------------------//
 
-  const char * generic_error_category::name() const
+  const char * generic_error_category::name() const BOOST_SYSTEM_NOEXCEPT
   {
     return "generic";
   }
@@ -154,12 +156,12 @@ namespace
   }
   //  system_error_category implementation  --------------------------------// 
 
-  const char * system_error_category::name() const
+  const char * system_error_category::name() const BOOST_SYSTEM_NOEXCEPT
   {
     return "system";
   }
 
-  error_condition system_error_category::default_error_condition( int ev ) const
+  error_condition system_error_category::default_error_condition( int ev ) const BOOST_SYSTEM_NOEXCEPT
   {
     switch ( ev )
     {
@@ -414,13 +416,13 @@ namespace boost
                                          //  address for comparison purposes
 # endif
 
-    BOOST_SYSTEM_DECL const error_category & system_category()
+    BOOST_SYSTEM_DECL const error_category & system_category() BOOST_SYSTEM_NOEXCEPT
     {
       static const system_error_category  system_category_const;
       return system_category_const;
     }
 
-    BOOST_SYSTEM_DECL const error_category & generic_category()
+    BOOST_SYSTEM_DECL const error_category & generic_category() BOOST_SYSTEM_NOEXCEPT
     {
       static const generic_error_category generic_category_const;
       return generic_category_const;
@@ -428,3 +430,4 @@ namespace boost
 
   } // namespace system
 } // namespace boost
+#endif
