--- src/huf.c.orig	2000-10-05 17:35:49 UTC
+++ src/huf.c
@@ -219,9 +219,7 @@ send_block( /* void */ )
 
 /* ------------------------------------------------------------------------ */
 void
-output_st1(c, p)
-	unsigned short  c;
-	unsigned short  p;
+output_st1(unsigned short c, unsigned short p)
 {
 	static unsigned short cpos;
 
