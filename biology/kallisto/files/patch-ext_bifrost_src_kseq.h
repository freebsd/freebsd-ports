--- ext/bifrost/src/kseq.h.orig	2026-01-20 17:34:25 UTC
+++ ext/bifrost/src/kseq.h
@@ -32,6 +32,12 @@
 #include <string.h>
 #include <stdlib.h>
 
+// Prevent redefinition of kstring_t below
+#include <htslib/kstring.h>
+
+// Prevent redefinition of kstring_t below
+#include <htslib/kstring.h>
+
 #define KS_SEP_SPACE 0 // isspace(): \t, \n, \v, \f, \r
 #define KS_SEP_TAB   1 // isspace() && !' '
 #define KS_SEP_LINE  2 // line separator: "\n" (Unix) or "\r\n" (Windows)
