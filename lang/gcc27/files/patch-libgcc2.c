--- libgcc2.c.orig	Sun Nov 26 11:39:21 1995
+++ libgcc2.c	Mon Mar 20 13:29:11 2000
@@ -2106,9 +2106,7 @@
     (*p++) ();
 #endif
 }
-#endif
 
-#ifndef INIT_SECTION_ASM_OP
 /* Run all the global constructors on entry to the program.  */
 
 #ifndef ON_EXIT
@@ -2128,9 +2126,7 @@
   DO_GLOBAL_CTORS_BODY;
   ON_EXIT (__do_global_dtors, 0);
 }
-#endif /* no INIT_SECTION_ASM_OP */
 
-#if !defined (INIT_SECTION_ASM_OP) || defined (INVOKE__main)
 /* Subroutine called automatically by `main'.
    Compiling a global function named `main'
    produces an automatic call to this function at the beginning.
@@ -2165,7 +2161,7 @@
 
 /* We declare the lists here with two elements each,
    so that they are valid empty lists if no other definition is loaded.  */
-#if !defined(INIT_SECTION_ASM_OP) && !defined(CTOR_LISTS_DEFINED_EXTERNALLY)
+#if (!defined(INIT_SECTION_ASM_OP) || !defined(OBJECT_FORMAT_ELF)) && !defined(CTOR_LISTS_DEFINED_EXTERNALLY)
 #if defined(__NeXT__) || defined(_AIX)
 /* After 2.3, try this definition on all systems.  */
 func_ptr __CTOR_LIST__[2] = {0, 0};
