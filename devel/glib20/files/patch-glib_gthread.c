--- glib/gthread.c.orig	Mon Mar 14 05:02:07 2005
+++ glib/gthread.c	Wed Jul 20 19:44:08 2005
@@ -42,24 +42,8 @@
 
 #include "glib.h"
 #include "gthreadinit.h"
+#include "gthreadprivate.h"
 #include "galias.h"
-
-#if GLIB_SIZEOF_SYSTEM_THREAD == SIZEOF_VOID_P
-# define g_system_thread_equal_simple(thread1, thread2)			\
-   ((thread1).dummy_pointer == (thread2).dummy_pointer)
-# define g_system_thread_assign(dest, src)				\
-   ((dest).dummy_pointer = (src).dummy_pointer)
-#else /* GLIB_SIZEOF_SYSTEM_THREAD != SIZEOF_VOID_P */
-# define g_system_thread_equal_simple(thread1, thread2)			\
-   (memcmp (&(thread1), &(thread2), GLIB_SIZEOF_SYSTEM_THREAD) == 0)
-# define g_system_thread_assign(dest, src)				\
-   (memcpy (&(dest), &(src), GLIB_SIZEOF_SYSTEM_THREAD))
-#endif /* GLIB_SIZEOF_SYSTEM_THREAD == SIZEOF_VOID_P */
-
-#define g_system_thread_equal(thread1, thread2)				\
-  (g_thread_functions_for_glib_use.thread_equal ? 			\
-   g_thread_functions_for_glib_use.thread_equal (&(thread1), &(thread2)) :\
-   g_system_thread_equal_simple((thread1), (thread2)))
 
 GQuark 
 g_thread_error_quark (void)
