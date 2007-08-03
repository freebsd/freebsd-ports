--- src/main.cc.orig	2007-08-03 16:32:02.000000000 +0200
+++ src/main.cc	2007-08-03 16:32:36.000000000 +0200
@@ -4,6 +4,7 @@
 *                                   *
 \***********************************/
 
+#include <sys/types.h>
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
@@ -44,7 +45,7 @@
 void on_fsb_clicked (GtkButton *button, gpointer user_data)
 {
   button = button;
-  if ((int)user_data == 0) System->FileSelectionOK();
+  if ((intptr_t)user_data == 0) System->FileSelectionOK();
   else System->FileSelectionCancel();
 }
 
