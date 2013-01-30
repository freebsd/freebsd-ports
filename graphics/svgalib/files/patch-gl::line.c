--- gl/line.c.orig	1999-12-05 08:32:54.000000000 +0100
+++ gl/line.c	2013-01-26 21:25:52.000000000 +0100
@@ -90,13 +90,13 @@ static inline int gl_regioncode (int x, 
 
 #else
 
-#define INC_IF_NEG(y, result)				\
-{							\
-	__asm__("btl $31,%1\n\t"			\
-		"adcl $0,%0"				\
-		: "=r" ((int) result)			\
-		: "rm" ((int) (y)), "0" ((int) result)	\
-		);					\
+#define INC_IF_NEG(y, result)			\
+{						\
+	__asm__("btl $31,%1\n\t"		\
+		"adcl $0,%0"			\
+		: "=r" (result)			\
+		: "rm" (y), "0" (result)	\
+		);				\
 }
 
 static inline int gl_regioncode (int x, int y)
