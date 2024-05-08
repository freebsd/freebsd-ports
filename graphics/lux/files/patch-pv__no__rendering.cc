--- pv_no_rendering.cc.orig	2024-04-23 12:53:51 UTC
+++ pv_no_rendering.cc
@@ -14875,7 +14875,9 @@ int main ( int argc , const char * argv[] )
 #endif
 
   OIIO::geterror() ;
+#if OIIO_VERSION_MAJOR * 100 + OIIO_VERSION_MINOR >= 205
   OIIO::shutdown() ;
+#endif
 
   std::cout << "exiting normally" << std::endl ;
 
