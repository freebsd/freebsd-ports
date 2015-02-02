--- src/sdltiles.cpp.orig	2014-11-17 06:09:38.000000000 +0300
+++ src/sdltiles.cpp	2014-11-30 13:31:51.462125514 +0300
@@ -1,4 +1,5 @@
 #if (defined TILES)
+#include <sys/param.h>
 #include "catacurse.h"
 #include "options.h"
 #include "output.h"
@@ -1213,8 +1214,8 @@ static void save_font_list()
     wordexp("~/Library/Fonts", &exp, 0);
     font_folder_list(fout, exp.we_wordv[0]);
     wordfree(&exp);*/
-#elif (defined linux || defined __linux)
-    font_folder_list(fout, "/usr/share/fonts");
+#elif (defined linux || defined __linux || defined __FreeBSD__)
+    font_folder_list(fout, "/usr/local/lib/X11/fonts");
     font_folder_list(fout, "/usr/local/share/fonts");
     wordexp_t exp;
     wordexp("~/.fonts", &exp, 0);
