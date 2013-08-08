--- lib-src/enigma-core/ecl_alist.hh.orig	2007-09-08 16:20:05.000000000 +0400
+++ lib-src/enigma-core/ecl_alist.hh	2013-07-10 23:10:11.780119603 +0400
@@ -61,7 +61,7 @@
 	VAL &operator[] (const key_type &key) { 
             iterator i=find(key);
             if (i==this->end())
-                i=insert(this->end(), make_pair(key, VAL()));
+                i=this->insert(this->end(), make_pair(key, VAL()));
             return i->second;
         }
     };
