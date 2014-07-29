
$FreeBSD$

--- gmodule/gmodule-dl.c	2001/12/12 04:39:42	1.1
+++ gmodule/gmodule-dl.c	2001/12/12 04:41:05
@@ -100,6 +100,7 @@
 static gpointer
 _g_module_self (void)
 {
+#ifndef __FreeBSD__
   gpointer handle;
   
   /* to query symbols from the program itself, special link options
@@ -111,6 +112,9 @@
     g_module_set_error (fetch_dlerror ());
   
   return handle;
+#else
+  return RTLD_DEFAULT;
+#endif
 }
 
 static void
