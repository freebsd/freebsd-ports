--- include/kiway.h.orig	2014-05-23 15:44:36.884457126 +0200
+++ include/kiway.h	2014-05-23 15:45:05.138279780 +0200
@@ -115,5 +115,5 @@
 #define KIFACE_INSTANCE_NAME_AND_VERSION   "KIFACE_1"
 
-#if defined(__linux__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
  #define LIB_ENV_VAR    wxT( "LD_LIBRARY_PATH" )
 #elif defined(__WXMAC__)
