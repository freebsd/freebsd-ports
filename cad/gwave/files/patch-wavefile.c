--- spicefile/wavefile.c~	Sun Jun 16 12:16:05 2002
+++ spicefile/wavefile.c	Sun Jun 16 12:01:26 2002
@@ -32,6 +32,7 @@
 
 
 #ifdef HAVE_POSIX_REGEXP
+#include <sys/types.h>
 #include <regex.h>
 #define REGEXP_T regex_t
 #define regexp_test(c,s) (regexec((c), (s), 0, NULL, 0) == 0)
