diff -urN ../o2em117src.old/src/timefunc.c ./src/timefunc.c
--- ../o2em117src.old/src/timefunc.c	Fri Jun 24 16:02:21 2005
+++ ./src/timefunc.c	Fri Jun 24 16:00:46 2005
@@ -43,7 +43,7 @@
 
 #elif defined(ALLEGRO_UNIX) || defined(ALLEGRO_LINUX)
 
-#ifdef _BSD_SOURCE
+#if defined(_BSD_SOURCE) || defined(FREEBSD)
 
 /* Unix with gettimeofday */
 long gettimeticks(void){
