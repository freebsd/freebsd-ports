--- he2/aString.h.orig	2001-03-14 09:04:03 UTC
+++ he2/aString.h
@@ -162,7 +162,6 @@ friend char *areplicate(char c, int count) ;
    void delete_ch(int at) ;
 friend char *areplicate(char c, int count) ;
 } ;
-
-
+char *areplicate(char c, int count) ;
 
 #endif
