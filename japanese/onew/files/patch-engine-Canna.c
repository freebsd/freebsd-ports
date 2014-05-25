--- engine/Canna.c.orig	1995-06-29 01:13:26.000000000 +0900
+++ engine/Canna.c	2014-05-25 12:05:08.000000000 +0900
@@ -33,6 +33,7 @@
 static int ready;
 static int CID;
 static int nbunsetsu;
+static void disp_kanji_buf(int);
 int ONEW_CannarcDone;
 
 static ONEWkanakan_ready()
@@ -102,7 +103,6 @@
 	int comch;
 	int rcode;
 	char yomibuf[1024];
-	static disp_kanji_buf();
 
 	Onew_setupYomistr(startch,yomi,yomibuf);
 	yomi = yomibuf;
@@ -182,7 +182,7 @@
 {
 }
 
-static disp_kanji_buf(so)
+static void disp_kanji_buf(so)
 {	char kanji[1024];
 	char left[1024],cur[1024],right[1024];
 	int curbi,bi;
