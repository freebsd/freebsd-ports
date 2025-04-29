--- libgcc/enable-execute-stack-mprotect.c.orig	2024-11-23 12:39:04 UTC
+++ libgcc/enable-execute-stack-mprotect.c
@@ -30,10 +30,11 @@ static int need_enable_exec_stack;
 
 static int need_enable_exec_stack;
 
-static void check_enabling (void) __attribute__ ((unused));
 extern void __enable_execute_stack (void *);
 
 #if defined __sun__ && defined __svr4__
+static void check_enabling (void) __attribute__ ((unused));
+
 static void __attribute__ ((constructor))
 check_enabling (void)
 {
