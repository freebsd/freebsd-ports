
$FreeBSD$

--- dfa.c.orig
+++ dfa.c
@@ -122,7 +122,6 @@
 static void dfamust PARAMS ((struct dfa *dfa));
 
 static ptr_t xcalloc PARAMS ((size_t n, size_t s));
-static ptr_t xmalloc PARAMS ((size_t n));
 static ptr_t xrealloc PARAMS ((ptr_t p, size_t n));
 #ifdef DEBUG
 static void prtok PARAMS ((token t));
