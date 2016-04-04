--- src/sdltiles.cpp.orig	2015-03-09 05:25:34 UTC
+++ src/sdltiles.cpp
@@ -1214,7 +1214,7 @@ static void save_font_list()
     wordexp("~/Library/Fonts", &exp, 0);
     font_folder_list(fout, exp.we_wordv[0]);
     wordfree(&exp);*/
-#elif (defined linux || defined __linux)
+#elif (defined linux || defined __linux || defined __FreeBSD__)
     font_folder_list(fout, "/usr/share/fonts");
     font_folder_list(fout, "/usr/local/share/fonts");
     wordexp_t exp;
