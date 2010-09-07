--- cuneiform_src/Kern/hhh/tigerh/h/c_types.h	2010-06-30 13:54:18.000000000 +0300
+++ cuneiform_src/Kern/hhh/tigerh/h/c_types.h	2010-09-06 03:21:03.000000000 +0300
@@ -79,12 +79,6 @@
 /*--------------------- Include standart h-files -----------------------*/
 
 #include <stdio.h>
-
-/* solves conflict with bsd <strings.h> */
-#if defined(__FreeBSD__)
-#undef __BSD_VISIBLE
-#endif
-
 #include <string.h>
 
 #include "cttypes.h"
--- cuneiform_src/Kern/hhh/tigerh/h/extract.h	2010-06-30 13:54:25.000000000 +0300
+++ cuneiform_src/Kern/hhh/tigerh/h/extract.h	2010-09-06 03:21:12.000000000 +0300
@@ -83,7 +83,7 @@
 # include "c_types.h"
 # include "lterrors.h"
 # include "roots.h"
-# include "strings.h"
+# include "cf_strings.h"
 # include "madebug.h"
 # include "layout.h"
 
--- cuneiform_src/Kern/hrstr/extract.h	2010-06-30 13:54:25.000000000 +0300
+++ cuneiform_src/Kern/hrstr/extract.h	2010-09-06 03:20:48.000000000 +0300
@@ -72,7 +72,7 @@
 
 # include "lterrors.h"
 # include "roots.h"
-# include "strings.h"
+# include "cf_strings.h"
 # include "madebug.h"
 # include "layout.h"
 
