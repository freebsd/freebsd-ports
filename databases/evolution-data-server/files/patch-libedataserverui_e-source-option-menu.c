--- libedataserverui/e-source-option-menu.c.orig	Tue Nov 23 13:50:14 2004
+++ libedataserverui/e-source-option-menu.c	Tue Nov 23 13:50:33 2004
@@ -24,6 +24,8 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
+
 #include <gtk/gtkmenu.h>
 #include <gtk/gtkmenuitem.h>
 
