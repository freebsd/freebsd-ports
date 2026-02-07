--- src/ptr.h.orig	2020-07-10 20:58:54 UTC
+++ src/ptr.h
@@ -64,12 +64,12 @@ char *memchrs(char *p, int lenp, char *q, int lenq);
 char *memrchrs(char *p, int lenp, char *q, int lenq);
 #ifdef _GNU_SOURCE
 # define memfind memmem
+char *memrchr(char *p, int lenp, char c);
 #else
 char *memfind(char *hay, int haylen, char *needle, int needlelen);
 /* TODO: watch memrchr, it is defined differently here than under _GNU_SOURCE,
  * so it could cause bizarre results if a module makes use of a library that
  * uses it */
-char *memrchr(char *p, int lenp, char c);
 #endif
 
 #endif /* _PTR_H_ */
