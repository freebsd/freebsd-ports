--- adnsmodule.c.orig        2018-08-11 22:10:36 UTC
+++ adnsmodule.c
@@ -6,6 +6,7 @@ any later version.
 */
 
 #include <Python.h>
+#include <sys/endian.h>
 #include <adns.h>
 #include <string.h>
 #include <assert.h>
