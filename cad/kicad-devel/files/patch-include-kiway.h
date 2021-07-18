--- include/kiway.h.orig	2021-06-08 00:34:09 UTC
+++ include/kiway.h
@@ -113,7 +113,7 @@
 #define KIFACE_INSTANCE_NAME_AND_VERSION   "KIFACE_1"
 
 #ifndef SWIG
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
  #define LIB_ENV_VAR    wxT( "LD_LIBRARY_PATH" )
 #elif defined(__WXMAC__)
  #define LIB_ENV_VAR    wxT( "DYLD_LIBRARY_PATH" )
