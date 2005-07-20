--- glib/gthreadprivate.h.orig	Wed Jul 20 19:44:08 2005
+++ glib/gthreadprivate.h	Wed Jul 20 19:44:08 2005
@@ -0,0 +1,50 @@
+/* gthreadprivate.h
+ *
+ * Copyright 1998 Sebastian Wilhelmi; University of Karlsruhe
+ *                Owen Taylor
+ *
+ * This library is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2 of the License, or (at your option) any later version.
+ *
+ * This library is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General Public
+ * License along with this library; if not, write to the
+ * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+ * Boston, MA 02111-1307, USA.
+ */
+
+#ifndef __G_THREAD_PRIVATE_H__
+#define __G_THREAD_PRIVATE_H__
+
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+G_BEGIN_DECLS
+
+#if GLIB_SIZEOF_SYSTEM_THREAD == SIZEOF_VOID_P
+# define g_system_thread_equal_simple(thread1, thread2)			\
+   ((thread1).dummy_pointer == (thread2).dummy_pointer)
+# define g_system_thread_assign(dest, src)				\
+   ((dest).dummy_pointer = (src).dummy_pointer)
+#else /* GLIB_SIZEOF_SYSTEM_THREAD != SIZEOF_VOID_P */
+# define g_system_thread_equal_simple(thread1, thread2)			\
+   (memcmp (&(thread1), &(thread2), GLIB_SIZEOF_SYSTEM_THREAD) == 0)
+# define g_system_thread_assign(dest, src)				\
+   (memcpy (&(dest), &(src), GLIB_SIZEOF_SYSTEM_THREAD))
+#endif /* GLIB_SIZEOF_SYSTEM_THREAD == SIZEOF_VOID_P */
+
+#define g_system_thread_equal(thread1, thread2)				\
+  (g_thread_functions_for_glib_use.thread_equal ? 			\
+   g_thread_functions_for_glib_use.thread_equal (&(thread1), &(thread2)) :\
+   g_system_thread_equal_simple((thread1), (thread2)))
+
+G_END_DECLS
+
+#endif /* __G_THREAD_PRIVATE_H__ */
