--- agraph/agraph.h.orig	Tue Apr 18 05:54:03 2000
+++ agraph/agraph.h	Tue Oct 17 17:51:06 2000
@@ -45,6 +45,8 @@
 #define NILsym			NIL(Agsym_t*)
 #endif
 
+typedef unsigned long 		ulong;
+
 /* forward struct type declarations */
 typedef struct Agtag_s		Agtag_t;
 typedef struct Agobj_s		Agobj_t;	/* generic object header */
