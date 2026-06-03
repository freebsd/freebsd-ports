--- regex.c.orig	2026-01-27 18:52:19 UTC
+++ regex.c
@@ -63,6 +63,7 @@
    GNU regex allows.  Include it before <regex.h>, which correctly
    #undefs RE_DUP_MAX and sets it to the right value.  */
 #include <limits.h>
+#include <stdbool.h>
 
 #include <regex.h>
 #include "regex_internal.h"
@@ -70,6 +71,7 @@
 #include "regex_internal.c"
 #include "regcomp.c"
 #include "regexec.c"
+#include "malloc/dynarray_resize.c"
 
 /* Binary backward compatibility.  */
 #if _LIBC
