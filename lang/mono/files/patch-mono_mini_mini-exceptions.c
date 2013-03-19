
$FreeBSD$

--- mono/mini/mini-exceptions.c.orig
+++ mono/mini/mini-exceptions.c
@@ -2002,10 +2002,10 @@
 
 	sa.ss_sp = tls->signal_stack;
 	sa.ss_size = MONO_ARCH_SIGNAL_STACK_SIZE;
-#if __APPLE__
-	sa.ss_flags = 0;
-#else
+#ifdef __linux__
 	sa.ss_flags = SS_ONSTACK;
+#else
+	sa.ss_flags = 0;
 #endif
 	g_assert (sigaltstack (&sa, NULL) == 0);
 
