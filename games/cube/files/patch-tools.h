--- ./tools.h.orig	Sun Aug 14 19:09:22 2005
+++ ./tools.h	Sat Jul 29 20:59:06 2006
@@ -147,6 +147,8 @@
     void allocnext(size_t allocsize);
 };
 
+pool *gp(); 
+
 template <class T> struct vector
 {
     T *buf;
@@ -270,7 +272,6 @@
 
 #define enumerate(ht,t,e,b) loopi(ht->size) for(ht->enumc = ht->table[i]; ht->enumc; ht->enumc = ht->enumc->next) { t e = &ht->enumc->data; b; }
 
-pool *gp(); 
 inline char *newstring(char *s)        { return gp()->string(s);    };
 inline char *newstring(char *s, size_t l) { return gp()->string(s, l); };
 inline char *newstringbuf(char *s)     { return gp()->stringbuf(s); };
