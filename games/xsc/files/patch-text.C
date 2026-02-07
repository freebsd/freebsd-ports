--- text.C.orig	2013-04-05 21:18:39 UTC
+++ text.C
@@ -27,7 +27,7 @@ static const char *const file_id =
 #include "text.h"
 
 
-Text::Text(void)
+Text::Text(void) : message(NULL), length(0)
 {
     //fprintf(stderr, "Text::Text()\n");
     set_scale(6.0);
