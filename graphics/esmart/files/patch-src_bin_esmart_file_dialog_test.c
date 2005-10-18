--- src/bin/esmart_file_dialog_test.c.orig	Tue May  3 13:32:05 2005
+++ src/bin/esmart_file_dialog_test.c	Tue Oct 18 17:31:25 2005
@@ -8,6 +8,7 @@
  * $ esmart_file_dialog_test /path/to/my_custom/theme.eet 
  * to test a custom theme you've written for it
  */
+#include <stdio.h>
 #include <Ecore.h>
 #include <Edje.h>
 #include <Ecore_Evas.h>
