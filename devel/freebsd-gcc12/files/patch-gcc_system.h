--- gcc/system.h.orig	2023-05-08 12:14:40 UTC
+++ gcc/system.h
@@ -203,19 +203,6 @@ extern int fprintf_unlocked (FILE *, const char *, ...
 #endif
 #endif
 
-/* There are an extraordinary number of issues with <ctype.h>.
-   The last straw is that it varies with the locale.  Use libiberty's
-   replacement instead.  */
-#include "safe-ctype.h"
-
-#include <sys/types.h>
-
-#include <errno.h>
-
-#if !defined (errno) && defined (HAVE_DECL_ERRNO) && !HAVE_DECL_ERRNO
-extern int errno;
-#endif
-
 #ifdef __cplusplus
 #if defined (INCLUDE_ALGORITHM) || !defined (HAVE_SWAP_IN_UTILITY)
 # include <algorithm>
@@ -243,6 +230,19 @@ extern int errno;
 # include <new>
 # include <utility>
 # include <type_traits>
+#endif
+
+/* There are an extraordinary number of issues with <ctype.h>.
+   The last straw is that it varies with the locale.  Use libiberty's
+   replacement instead.  */
+#include "safe-ctype.h"
+
+#include <sys/types.h>
+
+#include <errno.h>
+
+#if !defined (errno) && defined (HAVE_DECL_ERRNO) && !HAVE_DECL_ERRNO
+extern int errno;
 #endif
 
 /* Some of glibc's string inlines cause warnings.  Plus we'd rather
