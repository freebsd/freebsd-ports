--- rpython/rlib/rvmprof/src/shared/vmp_stack.c.orig	2017-10-03 10:49:20 UTC
+++ rpython/rlib/rvmprof/src/shared/vmp_stack.c
@@ -29,6 +29,7 @@ static int (*unw_get_proc_name)(unw_curs
 static int (*unw_is_signal_frame)(unw_cursor_t *) = NULL;
 static int (*unw_getcontext)(unw_context_t *) = NULL;
 #else
+#define UNW_LOCAL_ONLY
 #include <libunwind.h>
 #endif
 
