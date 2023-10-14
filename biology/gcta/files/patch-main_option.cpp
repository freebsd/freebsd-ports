--- main/option.cpp.orig	2023-10-13 13:49:25 UTC
+++ main/option.cpp
@@ -1112,10 +1112,10 @@ void option(int option_num, char* option_str[])
 
 #ifdef _WIN32
 	    if(chbuf != '\\') ref_ld_dirt = ref_ld_dirt + '\\';
-#elif defined __linux__ || defined __APPLE__
+#elif defined __FreeBSD__ || defined __linux__ || defined __APPLE__
 	    if(chbuf != '/') ref_ld_dirt = ref_ld_dirt + '/';
 #else
-#error Only Windows, Mac and Linux are supported.
+#error Only FreeBSD, Windows, Mac and Linux are supported.
 #endif
             LOGGER << "--ref-ld-chr " << ref_ld_dirt << endl;
         } else if (strcmp(argv[i], "--w-ld-chr") == 0) {
@@ -1124,10 +1124,10 @@ void option(int option_num, char* option_str[])
             chbuf = w_ld_dirt.back();
 #ifdef _WIN32
             if(chbuf != '\\') w_ld_dirt = w_ld_dirt + '\\';
-#elif defined __linux__ || defined __APPLE__
+#elif defined __FreeBSD__ || defined __linux__ || defined __APPLE__
             if(chbuf != '/') w_ld_dirt = w_ld_dirt + '/';
 #else
-#error Only Windows, Mac and Linux are supported.
+#error Only FreeBSD, Windows, Mac and Linux are supported.
 #endif
 
             LOGGER << "--w-ld-chr " << w_ld_dirt << endl;
