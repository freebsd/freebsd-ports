https://svnweb.freebsd.org/changeset/base/294930

stack_printer.cpp:329:18: error: assigning to 'char *' from incompatible type 'void *'
      ss.ss_sp = (void*)alternate_stack;
                 ^~~~~~~~~~~~~~~~~~~~~~

--- stack_printer.cpp.orig	2017-10-24 09:45:42 UTC
+++ stack_printer.cpp
@@ -326,7 +326,11 @@ int printStacktraceWithGdb() {
       stack_t ss = {};
       /* malloc is usually used here, I'm not 100% sure my static allocation
          is valid but it seems to work just fine. */
+#if defined(__DragonFly__)
+      ss.ss_sp = (char*)alternate_stack;
+#else
       ss.ss_sp = (void*)alternate_stack;
+#endif
       ss.ss_size = SIGSTKSZ;
       ss.ss_flags = 0;
 
