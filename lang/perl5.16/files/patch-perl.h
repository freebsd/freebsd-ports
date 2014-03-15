--- perl.h.orig	2013-03-04 16:16:22.000000000 +0100
+++ perl.h	2014-03-15 10:42:19.000000000 +0100
@@ -359,7 +359,11 @@
 /* Rats: if dTHR is just blank then the subsequent ";" throws an error */
 /* Declaring a *function*, instead of a variable, ensures that we don't rely
    on being able to suppress "unused" warnings.  */
+#ifdef __cplusplus
+#define dNOOP (void)0
+#else
 #define dNOOP extern int Perl___notused(void)
+#endif
 
 #ifndef pTHX
 /* Don't bother defining tTHX and sTHX; using them outside
