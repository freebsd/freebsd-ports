--- screen.h.orig	2004-06-22 13:24:19 UTC
+++ screen.h
@@ -20,7 +20,7 @@ extern unsigned char start_font1[2048];
 extern unsigned char start_font2[4096];
 extern unsigned char start_font3[4096];
 
-int monthgraph_style;
+extern int monthgraph_style;
 
 /* This is on in screen_full_refresh, used in *_refresh() */
 extern char screen_refreshing;
