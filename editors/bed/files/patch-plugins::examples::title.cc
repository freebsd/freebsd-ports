--- plugins/examples/title.cc.orig	Fri Mar 26 10:30:14 2004
+++ plugins/examples/title.cc	Fri Mar 26 10:31:01 2004
@@ -66,14 +66,14 @@
 		}
 #endif
 #ifdef TTYNAME
-#ifdef HAS_TTYNAME_R
+#if defined(HAS_TTYNAME_R) && !defined(__FreeBSD__)
 	char nametty[15];
 #else
 	char *nametty;
 #endif
 //	ptsname_r(titlebuf,ttys[i],MAXTITLE-nr);
 	if(isatty(STDOUT_FILENO)) {
-#ifdef HAS_TTYNAME_R
+#if defined(HAS_TTYNAME_R) && !defined(__FreeBSD__)
 		if(!ttyname_r(STDOUT_FILENO,nametty,15)) {
 #else
 		if((nametty=ttyname(STDOUT_FILENO))) {
