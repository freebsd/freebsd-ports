--- src/kseq.h.orig	2019-11-04 16:28:52 UTC
+++ src/kseq.h
@@ -32,6 +32,9 @@
 #include <string.h>
 #include <stdlib.h>
 
+// Prevent redefinition of kstring_t below
+#include <htslib/kstring.h>
+
 #define KS_SEP_SPACE 0 // isspace(): \t, \n, \v, \f, \r
 #define KS_SEP_TAB   1 // isspace() && !' '
 #define KS_SEP_LINE  2 // line separator: "\n" (Unix) or "\r\n" (Windows)
