--- sal/osl/unx/interlck.c.orig	Mon Jul 22 17:51:34 2002
+++ sal/osl/unx/interlck.c	Mon Jul 22 18:03:42 2002
@@ -81,10 +81,10 @@
 	__asm__ __volatile__ (
 		"movl $1, %0\n\t"
 		"lock\n\t" 
-		"xadd %0, %2\n\t"
+		"xadd %0, %1\n\t"
 		"incl %0"
-	:	"=a" (nCount), "=m" (*pCount)
-	:	"m" (*pCount)
+	:	"=&a" (nCount), "+m" (*pCount)
+	:
 	:	"memory");
 }
 
@@ -95,10 +95,10 @@
 	__asm__ __volatile__ (
 		"movl $-1, %0\n\t"
 		"lock\n\t"
-		"xadd %0, %2\n\t"
+		"xadd %0, %1\n\t"
 		"decl %0"
-	:	"=a" (nCount), "=m" (*pCount)
-	:	"m" (*pCount)
+	:	"=&a" (nCount), "+m" (*pCount)
+	:
 	:	"memory");
 }
 
