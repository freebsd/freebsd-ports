--- ../regex/regex2.h.orig	2014-01-15 15:00:45.000000000 +0000
+++ ../regex/regex2.h
@@ -80,8 +80,8 @@ typedef int sopno;
 #define	OPRMASK	0xf8000000
 #define	OPDMASK	0x07ffffff
 #define	OPSHIFT	((unsigned)27)
-#define	OP(n)	((n)&OPRMASK)
-#define	OPND(n)	((n)&OPDMASK)
+#define	OP(n)	((unsigned)((n)&OPRMASK))
+#define	OPND(n)	((unsigned)((n)&OPDMASK))
 #define	SOP(op, opnd)	((op)|(opnd))
 /* operators			   meaning	operand			*/
 /*						(back, fwd are offsets)	*/
