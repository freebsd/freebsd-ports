--- main.c.orig	Fri Feb 11 17:11:52 2000
+++ main.c	Thu Mar 28 21:05:27 2002
@@ -62,7 +62,6 @@
 Alloc(unsigned int sz)
 {
 	void *		p;
-	extern void *	malloc(unsigned int);
 
 	p = malloc(sz);
 	if (!p)
@@ -75,7 +74,6 @@
 ReAlloc(void * xp, unsigned int sz)
 {
 	void *		p;
-	extern void *	realloc(void *, unsigned int);
 
 	p = realloc(xp, sz);
 	if (!p)
