--- jidctint.c.orig	Tue Nov  2 00:03:08 2004
+++ jidctint.c	Tue Nov  2 00:10:06 2004
@@ -173,32 +173,32 @@
  * Perform dequantization and inverse DCT on one block of coefficients.
  */
 #define __int64 unsigned long long
-	static	__int64 fix_029_n089n196	= 0x098ea46e098ea46e;
-	static	__int64 fix_n196_n089		= 0xc13be333c13be333;
-	static	__int64 fix_205_n256n039	= 0x41b3a18141b3a181;
-	static	__int64 fix_n039_n256		= 0xf384adfdf384adfd;
-	static	__int64 fix_307n256_n196	= 0x1051c13b1051c13b;
-	static	__int64 fix_n256_n196		= 0xadfdc13badfdc13b;
-	static	__int64 fix_150_n089n039	= 0x300bd6b7300bd6b7;
-	static	__int64 fix_n039_n089		= 0xf384e333f384e333;
-	static	__int64 fix_117_117			= 0x25a125a125a125a1;
-	static	__int64 fix_054_054p076		= 0x115129cf115129cf;
-	static	__int64 fix_054n184_054		= 0xd6301151d6301151;
+	const	__int64 fix_029_n089n196	= 0x098ea46e098ea46e;
+	const	__int64 fix_n196_n089		= 0xc13be333c13be333;
+	const	__int64 fix_205_n256n039	= 0x41b3a18141b3a181;
+	const	__int64 fix_n039_n256		= 0xf384adfdf384adfd;
+	const	__int64 fix_307n256_n196	= 0x1051c13b1051c13b;
+	const	__int64 fix_n256_n196		= 0xadfdc13badfdc13b;
+	const	__int64 fix_150_n089n039	= 0x300bd6b7300bd6b7;
+	const	__int64 fix_n039_n089		= 0xf384e333f384e333;
+	const	__int64 fix_117_117			= 0x25a125a125a125a1;
+	const	__int64 fix_054_054p076		= 0x115129cf115129cf;
+	const	__int64 fix_054n184_054		= 0xd6301151d6301151;
 
-	static	__int64 fix_054n184 		= 0xd630d630d630d630;
-	static	__int64 fix_054				= 0x1151115111511151;
-	static	__int64 fix_054p076			= 0x29cf29cf29cf29cf;
-	static	__int64 fix_n196p307n256	= 0xd18cd18cd18cd18c;
-	static	__int64 fix_n089n039p150	= 0x06c206c206c206c2;
-	static	__int64 fix_n256			= 0xadfdadfdadfdadfd;
-	static	__int64 fix_n039			= 0xf384f384f384f384;
-	static	__int64 fix_n256n039p205	= 0xe334e334e334e334;
-	static	__int64 fix_n196			= 0xc13bc13bc13bc13b;
-	static	__int64 fix_n089			= 0xe333e333e333e333;
-	static	__int64 fixn089n196p029		= 0xadfcadfcadfcadfc;
+	const	__int64 fix_054n184 		= 0xd630d630d630d630;
+	const	__int64 fix_054				= 0x1151115111511151;
+	const	__int64 fix_054p076			= 0x29cf29cf29cf29cf;
+	const	__int64 fix_n196p307n256	= 0xd18cd18cd18cd18c;
+	const	__int64 fix_n089n039p150	= 0x06c206c206c206c2;
+	const	__int64 fix_n256			= 0xadfdadfdadfdadfd;
+	const	__int64 fix_n039			= 0xf384f384f384f384;
+	const	__int64 fix_n256n039p205	= 0xe334e334e334e334;
+	const	__int64 fix_n196			= 0xc13bc13bc13bc13b;
+	const	__int64 fix_n089			= 0xe333e333e333e333;
+	const   __int64 fixn089n196p029		= 0xadfcadfcadfcadfc;	
 
-	static  __int64 const_0x2xx8		= 0x0000010000000100;
-	static  __int64 const_0x0808		= 0x0808080808080808;
+	const  __int64 const_0x2xx8		= 0x0000010000000100;
+	const  __int64 const_0x0808		= 0x0808080808080808;
 
 __inline void domidct8x8llmW(short *inptr, short *quantptr, int *wsptr,
 				   JSAMPARRAY outptr, int output_col);
