--- c-posix.c.orig	Thu Oct 24 01:03:51 2002
+++ c-posix.c	Fri Sep 26 23:38:36 2003
@@ -2788,7 +2788,11 @@
 #endif
 
 #ifdef SEM_VALUE_MAX
+#if SEM_VALUE_MAX > INT_MAX
+  gmaxnn("Semaphores_Value",INT_MAX);
+#else
   gmaxnn("Semaphores_Value",SEM_VALUE_MAX);
+#endif
 #else
 #ifdef _POSIX_SEM_VALUE_MAX
   gmaxn("Semaphores_Value",_POSIX_SEM_VALUE_MAX);
@@ -6344,7 +6348,7 @@
   g_struct_msghdr();
   gcmnt("local socket address");
   { struct sockaddr_un DUMMY;
-    ifprintf(fp,"   subtype sun_path_string is
+    ifprintf(fp,"   subtype sun_path_string is \
       POSIX_String (1 .. %d);\n", sizeof (DUMMY.sun_path));
   }
   g_struct_sockaddr_un();
