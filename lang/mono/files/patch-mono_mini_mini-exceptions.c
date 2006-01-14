--- mono/mini/mini-exceptions.c.orig	Tue Nov  1 09:07:14 2005
+++ mono/mini/mini-exceptions.c	Wed Nov 16 21:17:13 2005
@@ -915,7 +915,11 @@
 	tls->stack_size = stsize + getpagesize ();
 
 	/* Setup an alternate signal stack */
+#if defined(__FreeBSD__)
+	tls->signal_stack = mmap (0, MONO_ARCH_SIGNAL_STACK_SIZE, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANON, -1, 0);
+#else
 	tls->signal_stack = mmap (0, MONO_ARCH_SIGNAL_STACK_SIZE, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
+#endif
 	tls->signal_stack_size = MONO_ARCH_SIGNAL_STACK_SIZE;
 
 	g_assert (tls->signal_stack);
