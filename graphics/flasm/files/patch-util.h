--- util.h.orig	2020-01-07 17:07:08 UTC
+++ util.h
@@ -47,7 +47,7 @@ struct keyword {
     int token;
 };
 
-extern struct keyword *in_word_set(register const char *str, register unsigned int len);
+extern struct keyword *in_word_set(register const char *str, register size_t len);
 
 void checkByteOrder(void);
 int longintCompare(const void *ap, const void *bp);
