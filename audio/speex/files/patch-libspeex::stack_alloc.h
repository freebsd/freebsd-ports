
$FreeBSD$

--- libspeex/stack_alloc.h.orig	Wed Jun 11 17:10:53 2003
+++ libspeex/stack_alloc.h	Wed Jun 11 17:11:12 2003
@@ -48,7 +48,7 @@
 #else
 
 /*Aligns the stack to a 'size' boundary */
-#define ALIGN(stack, size) ((stack) += ((size) - (int)(stack)) & ((size) - 1))
+#define ALIGN(stack, size) ((stack) += ((size) - (long)(stack)) & ((size) - 1))
 
 /* Allocates 'size' elements of type 'type' on the stack */
 #define PUSH(stack, size, type) (ALIGN((stack),sizeof(type)),(stack)+=((size)*sizeof(type)),(type*)((stack)-((size)*sizeof(type))))
