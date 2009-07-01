--- src/fr-enum-types.c.orig	2009-06-30 20:34:58.000000000 +1000
+++ src/fr-enum-types.c	2009-06-30 20:35:02.000000000 +1000
@@ -4,7 +4,7 @@
 #include <glib-object.h>
 
 /* enumerations from "../../src/typedefs.h" */
-#include "../../src/typedefs.h"
+#include "typedefs.h"
 GType
 fr_compression_get_type (void)
 {
