--- src/shuf.c.orig	2000-10-04 14:57:38 UTC
+++ src/shuf.c
@@ -38,8 +38,7 @@ decode_start_st0( /*void*/ )
 
 /* ------------------------------------------------------------------------ */
 void
-encode_p_st0(j)
-	unsigned short  j;
+encode_p_st0(unsigned short j)
 {
 	unsigned short  i;
 
