--- aexcl/aexcl_play.cxx.orig	2005-12-16 14:17:00 UTC
+++ aexcl/aexcl_play.cxx
@@ -199,7 +199,7 @@ static int run_raop_play(void)
 {
 	const char *rargv[6];
 	char ip[32];
-	char *astr;
+	const char *astr;
 	char vol[8];
 
 	rargv[0]="raop_play";
