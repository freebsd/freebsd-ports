--- mzscheme/sconfig.h.orig	Wed Jul 26 18:00:43 2006
+++ mzscheme/sconfig.h	Fri Sep 22 15:23:14 2006
@@ -302,9 +302,23 @@
 
   /************** x86/FreeBSD with gcc ****************/
 
-# if defined(__FreeBSD__) && defined(i386)
+# if defined(__FreeBSD__)
 
-# define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-freebsd"
+#  if defined(__i386__)
+#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-freebsd"
+#   define REGISTER_POOR_MACHINE
+#   define MZ_USE_JIT_I386
+#   define FREEBSD_CONTROL_387
+#  elif defined(__amd64__)
+#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "amd64-freebsd"
+#   define REGISTER_POOR_MACHINE
+#   define MZ_USE_JIT_X86_64
+#  elif defined(__sparc64__)
+#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "sparc64-freebsd"
+#   define FLUSH_SPARC_REGISTER_WINDOWS
+#  else
+#   error Unported platform.
+#  endif
 
 # include "uconfig.h"
 # undef HAS_STANDARD_IOB
@@ -318,7 +332,6 @@
 # define USE_UNDERSCORE_SETJMP
 
 # define USE_IEEE_FP_PREDS
-# define FREEBSD_CONTROL_387
 # define POW_HANDLES_INF_CORRECTLY
 
 # define USE_DYNAMIC_FDSET_SIZE
@@ -327,9 +340,6 @@
 
 # define USE_TM_GMTOFF_FIELD
 
-# define REGISTER_POOR_MACHINE
-
-# define MZ_USE_JIT_I386
 # define MZ_JIT_USE_MPROTECT
 
 # define FLAGS_ALREADY_SET
