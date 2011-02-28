--- src/video/mmx.h	2009-10-12 23:07:15.000000000 +0000
+++ src/video/mmx.h	2010-04-13 14:25:40.530735004 +0000
@@ -355,7 +355,7 @@
 
 #define	mmx_r2m(op, reg, mem) \
 	__asm__ __volatile__ (#op " %%" #reg ", %0" \
-			      : "=X" (mem) \
+			      : "=m" (mem) \
 			      : /* nothing */ )
 
 #define	mmx_r2r(op, regs, regd) \
