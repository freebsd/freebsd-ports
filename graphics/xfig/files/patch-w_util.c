--- w_util.c.orig	Wed Dec 11 23:04:04 2002
+++ w_util.c	Wed Aug 31 09:49:42 2005
@@ -352,16 +352,6 @@
  * (use -1 if no line desired)
  */
 
-#include "SmeCascade.h"
-
-void
-test_callback(w, value, garbage)
-     Widget	    w;
-     XtPointer	    value, garbage;
-{
-  fprintf(stderr,"%d chosen\n",(int) value);
-}
-
 Widget
 make_pulldown_menu(entries, nent, divide_line, divide_message, parent, callback)
     char	   *entries[];
