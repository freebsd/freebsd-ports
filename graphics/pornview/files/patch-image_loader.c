--- src/support/image_loader.c.orig	2002-12-16 18:45:36.000000000 +0100
+++ src/support/image_loader.c	2009-04-19 13:58:56.000000000 +0200
@@ -81,7 +81,7 @@
 image_loader_stop (ImageLoader * il)
 {
 #ifdef USE_GTK2
-    GError *err;
+    GError *err = NULL;
 #endif
 
     if (!il)
@@ -174,7 +174,7 @@
     gint    c;
 
 #ifdef USE_GTK2
-    GError *err;
+    GError *err = NULL;
 #endif
 
     if (!il)
@@ -241,7 +241,7 @@
     int     b;
 
 #ifdef USE_GTK2
-    GError *err;
+    GError *err = NULL;
 #endif
 
     if (!il->loader || il->pixbuf)
