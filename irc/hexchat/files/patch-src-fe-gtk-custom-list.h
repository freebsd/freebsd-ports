--- src/fe-gtk/custom-list.h.orig	2013-04-02 03:07:55.000000000 +0200
+++ src/fe-gtk/custom-list.h	2013-04-04 21:09:51.000000000 +0200
@@ -22,6 +22,8 @@
 
 #include <gtk/gtk.h>
 
+GType custom_list_get_type (void);
+
 /* Some boilerplate GObject defines. 'klass' is used
  *   instead of 'class', because 'class' is a C++ keyword */
 
