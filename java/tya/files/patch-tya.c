--- ./tya.c.orig	Tue Jul  9 20:28:10 2002
+++ ./tya.c	Tue Oct 28 00:44:51 2003
@@ -786,7 +786,7 @@
 unsigned long  oldesp asm("anOldsp");
 unsigned long  oldebp asm("anOldbp");
 unsigned long  jumpTo asm("aJumpTo");
-#endif EXCEPTIONS_BY_SIGNALS
+#endif /* EXCEPTIONS_BY_SIGNALS */
 
 #define NEWGETCONTEXT
 #define OFF116v5 4	// 0 for 114v4a
@@ -916,16 +916,16 @@
    
    // restore old ebp and esp, push old eip on stack for exception handler
    // and jump there
-   asm volatile( "
-   movl $anOldbp, %eax
-   movl (%eax), %ebp
-   movl $anOldsp, %eax
-   movl (%eax), %esp
-   movl $anOldip, %eax
-   movl (%eax),%eax
-   pushl %eax
-   movl $aJumpTo, %eax
-   movl (%eax), %eax
+   asm volatile( "\
+   movl $anOldbp, %eax\
+   movl (%eax), %ebp\
+   movl $anOldsp, %eax\
+   movl (%eax), %esp\
+   movl $anOldip, %eax\
+   movl (%eax),%eax\
+   pushl %eax\
+   movl $aJumpTo, %eax\
+   movl (%eax), %eax\
    jmp *%eax" );
 #endif // EXCEPTIONS_BY_SIGNALS
    return HOOKRETVAL;		     
