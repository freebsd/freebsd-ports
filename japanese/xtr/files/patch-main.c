--- src/main.c.orig	Wed Jul 23 17:02:16 2003
+++ src/main.c	Wed Jul 23 17:03:32 2003
@@ -401,10 +401,10 @@
 int stdinmode;				/* 標準入力から入力 */
 uchar *ifilename;			/* 現在の入力ファイル名 */
 uchar *ifilename1;			/* 入力ファイル名の代表 */
-FILE *ifp = stdin;
+FILE *ifp;
 int stdoutmode;				/* 標準出力へ出力 */
 uchar *ofilename;
-FILE *ofp = stdout;
+FILE *ofp;
 uchar *bakfilename;			/* .BAK にリネームされた入力ファイル名 */
 
 
