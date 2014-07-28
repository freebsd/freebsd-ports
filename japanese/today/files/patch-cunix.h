--- cunix.h.orig	2011-04-16 21:25:44.000000000 +0900
+++ cunix.h	2011-04-16 21:27:40.000000000 +0900
@@ -40,7 +40,9 @@
 #define _T_TMPENV			"TEMP"			/* temporary 環境変数名 */
 #define _T_TMPENV2			"TMPDIR"		/* temporary 環境変数名 */
 #define _T_TMPDIR			"/tmp"			/* temporary directory */
+#if 0
 #define _T_SEARCH_DEFPATHS	"/usr/local/lib/today:/opt/local/lib/today:/usr/local/share/today:/opt/local/share/today:/usr/lib/today:/opt/lib/today:/usr/share/today:/opt/share/today:/usr/local/lib:/opt/local/lib:/usr/lib:/opt/lib"
+#endif
 											/* default search path list */
 #define _T_HOMEENV			"HOME"			/* home 環境変数 */
 #define _T_PATHENV			"PATH"			/* path 環境変数名 */
@@ -60,7 +62,7 @@
 #define _T_OUTFILE_DEFAULT	"%c%y%m%d.today"
 #define _T_OUTFILE_TMPNAME	"%p.today"
 
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 #define _T_ACCESS_ROK		R_OK
 #define _T_HAVE_STRTOK_R
 #define stricmp(a,b)		strcasecmp(a,b)
