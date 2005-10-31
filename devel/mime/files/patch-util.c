--- util.c.orig	Sun Oct 30 23:38:55 2005
+++ util.c	Sun Oct 30 23:39:26 2005
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
