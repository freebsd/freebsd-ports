--- source/src/tools.h.orig	Wed Sep 22 16:54:56 2004
+++ source/src/tools.h	Wed Sep 22 17:00:21 2004
@@ -136,6 +136,8 @@
     void allocnext(int allocsize);
 };
 
+pool *gp(); 
+
 template <class T> struct vector
 {
     T *buf;
@@ -259,7 +261,6 @@
 
 #define enumerate(ht,t,e,b) loopi(ht->size) for(ht->enumc = ht->table[i]; ht->enumc; ht->enumc = ht->enumc->next) { t e = &ht->enumc->data; b; }
 
-pool *gp(); 
 inline char *newstring(char *s)        { return gp()->string(s);    };
 inline char *newstring(char *s, int l) { return gp()->string(s, l); };
 inline char *newstringbuf(char *s)     { return gp()->stringbuf(s); };
