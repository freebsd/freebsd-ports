--- include/kiway.h.orig	2015-01-10 18:11:39.000000000 +0000
+++ include/kiway.h	2015-01-11 10:51:52.458174797 +0000
@@ -115,5 +115,5 @@
 #define KIFACE_INSTANCE_NAME_AND_VERSION   "KIFACE_1"
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
  #define LIB_ENV_VAR    wxT( "LD_LIBRARY_PATH" )
 #elif defined(__WXMAC__)
