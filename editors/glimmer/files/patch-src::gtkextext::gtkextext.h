
$FreeBSD$

--- src/gtkextext/gtkextext.h	2001/10/05 13:57:54	1.1
+++ src/gtkextext/gtkextext.h	2001/10/05 13:58:07
@@ -29,7 +29,7 @@
 #include <gtk/gtkadjustment.h>
 
 #include <sys/types.h>
-#include "../regex/regex.h"
+#include <gnuregex.h>
 
 #define GTK_TYPE_EXTEXT                  (gtk_extext_get_type ())
 #define GTK_EXTEXT(obj)                  (GTK_CHECK_CAST ((obj), GTK_TYPE_EXTEXT, GtkExText))
