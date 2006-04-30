
$FreeBSD$
  $MCom: ports/devel/glib20/files/patch-gmodule::gmodule-dl.c,v 1.16 2005/12/15 00:18:44 marcus Exp $

--- gmodule/gmodule-dl.c.orig	Sat Feb 17 08:28:07 2001
+++ gmodule/gmodule-dl.c	Fri Jan 18 09:48:45 2002
@@ -104,6 +104,7 @@
 static gpointer
 _g_module_self (void)
 {
+#ifndef __FreeBSD__
   gpointer handle;
   
   /* to query symbols from the program itself, special link options
@@ -115,6 +116,9 @@
     g_module_set_error (fetch_dlerror (TRUE));
   
   return handle;
+#else
+  return RTLD_DEFAULT;
+#endif
 }
 
 static void
