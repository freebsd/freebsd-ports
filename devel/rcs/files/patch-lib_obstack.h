--- lib/obstack.h.orig	2022-01-27 03:00:30 UTC
+++ lib/obstack.h
@@ -226,7 +226,7 @@ extern _OBSTACK_SIZE_T _obstack_memory_used (struct ob
    more memory.  This can be set to a user defined function which
    should either abort gracefully or use longjump - but shouldn't
    return.  The default action is to print a message and abort.  */
-extern __attribute_noreturn__ void (*obstack_alloc_failed_handler) (void);
+extern void (*obstack_alloc_failed_handler) (void);
 
 /* Exit value used when 'print_and_abort' is used.  */
 extern int obstack_exit_failure;
