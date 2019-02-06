--- src/stacktrace_powerpc-darwin-inl.h.orig	2016-08-25 05:12:24 UTC
+++ src/stacktrace_powerpc-darwin-inl.h
@@ -97,7 +97,11 @@ int GET_STACK_TRACE_OR_FRAMES {
   // different asm syntax.  I don't know quite the best way to discriminate
   // systems using the old as from the new one; I've gone with __APPLE__.
   // TODO(csilvers): use autoconf instead, to look for 'as --version' == 1 or 2
+#ifdef __FreeBSD__
+  __asm__ volatile ("mr %0,1" : "=r" (sp));
+#else
   __asm__ volatile ("mr %0,r1" : "=r" (sp));
+#endif
 
   // On PowerPC, the "Link Register" or "Link Record" (LR), is a stack
   // entry that holds the return address of the subroutine call (what
