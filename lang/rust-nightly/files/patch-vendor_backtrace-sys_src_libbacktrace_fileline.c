https://github.com/ianlancetaylor/libbacktrace/commit/0f06cda953cc4e26f38751c5b9f15ae8dfa5ff2d
https://github.com/rust-lang-nursery/libbacktrace/pull/1

--- vendor/backtrace-sys/src/libbacktrace/fileline.c.orig	2020-02-19 21:11:31 UTC
+++ vendor/backtrace-sys/src/libbacktrace/fileline.c
@@ -39,6 +39,10 @@ POSSIBILITY OF SUCH DAMAGE.  */
 #include <stdlib.h>
 #include <unistd.h>
 
+#if defined (HAVE_KERN_PROC_ARGS) || defined (HAVE_KERN_PROC)
+#include <sys/sysctl.h>
+#endif
+
 #include "backtrace.h"
 #include "internal.h"
 
@@ -46,6 +50,78 @@ POSSIBILITY OF SUCH DAMAGE.  */
 #define getexecname() NULL
 #endif
 
+#if !defined (HAVE_KERN_PROC_ARGS) && !defined (HAVE_KERN_PROC)
+
+#define sysctl_exec_name1(state, error_callback, data) NULL
+#define sysctl_exec_name2(state, error_callback, data) NULL
+
+#else /* defined (HAVE_KERN_PROC_ARGS) || |defined (HAVE_KERN_PROC) */
+
+static char *
+sysctl_exec_name (struct backtrace_state *state,
+		  int mib0, int mib1, int mib2, int mib3,
+		  backtrace_error_callback error_callback, void *data)
+{
+  int mib[4];
+  size_t len;
+  char *name;
+  size_t rlen;
+
+  mib[0] = mib0;
+  mib[1] = mib1;
+  mib[2] = mib2;
+  mib[3] = mib3;
+
+  if (sysctl (mib, 4, NULL, &len, NULL, 0) < 0)
+    return NULL;
+  name = (char *) backtrace_alloc (state, len, error_callback, data);
+  if (name == NULL)
+    return NULL;
+  rlen = len;
+  if (sysctl (mib, 4, name, &rlen, NULL, 0) < 0)
+    {
+      backtrace_free (state, name, len, error_callback, data);
+      return NULL;
+    }
+  return name;
+}
+
+#ifdef HAVE_KERN_PROC_ARGS
+
+static char *
+sysctl_exec_name1 (struct backtrace_state *state,
+		   backtrace_error_callback error_callback, void *data)
+{
+  /* This variant is used on NetBSD.  */
+  return sysctl_exec_name (state, CTL_KERN, KERN_PROC_ARGS, -1,
+			   KERN_PROC_PATHNAME, error_callback, data);
+}
+
+#else
+
+#define sysctl_exec_name1(state, error_callback, data) NULL
+
+#endif
+
+#ifdef HAVE_KERN_PROC
+
+static char *
+sysctl_exec_name2 (struct backtrace_state *state,
+		   backtrace_error_callback error_callback, void *data)
+{
+  /* This variant is used on FreeBSD.  */
+  return sysctl_exec_name (state, CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1,
+			   error_callback, data);
+}
+
+#else
+
+#define sysctl_exec_name2(state, error_callback, data) NULL
+
+#endif
+
+#endif /* defined (HAVE_KERN_PROC_ARGS) || |defined (HAVE_KERN_PROC) */
+
 /* Initialize the fileline information from the executable.  Returns 1
    on success, 0 on failure.  */
 
@@ -83,7 +159,7 @@ fileline_initialize (struct backtrace_state *state,
 
   descriptor = -1;
   called_error_callback = 0;
-  for (pass = 0; pass < 5; ++pass)
+  for (pass = 0; pass < 7; ++pass)
     {
       int does_not_exist;
 
@@ -105,6 +181,12 @@ fileline_initialize (struct backtrace_state *state,
 	  snprintf (buf, sizeof (buf), "/proc/%ld/object/a.out",
 		    (long) getpid ());
 	  filename = buf;
+	  break;
+	case 5:
+	  filename = sysctl_exec_name1 (state, error_callback, data);
+	  break;
+	case 6:
+	  filename = sysctl_exec_name2 (state, error_callback, data);
 	  break;
 	default:
 	  abort ();
