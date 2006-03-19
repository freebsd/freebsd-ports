--- src/os_dependent.cc.orig	Thu Aug 25 23:57:41 2005
+++ src/os_dependent.cc	Sun Mar 19 20:45:54 2006
@@ -349,7 +349,7 @@
 
 char * get_error_message() {
 #ifndef _WIN32
-  return dlerror();
+  return (char *) dlerror();
 #else
   return g_win32_error_message(GetLastError());
 #endif
