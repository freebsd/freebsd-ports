--- ./util.c.orig	2003-09-16 01:37:19.000000000 +0200
+++ ./util.c	2014-02-18 11:11:32.986338150 +0100
@@ -31,7 +31,7 @@
 
 #if 0
 char *
-memmem(const char *big, int blen, const char *lit, int llen)
+memmemory(const char *big, int blen, const char *lit, int llen)
 {
 	const char *pos;
 
@@ -61,7 +61,7 @@
 }
 
 const char *
-memmem(const char *T, size_t n, const char *P, size_t m)
+memmemory(const char *T, size_t n, const char *P, size_t m)
 {
 	static unsigned int q = 4294967291u;
 	static unsigned int d = 256;
