--- PGPLOT.xs.orig	Wed Sep 27 17:43:36 UTC
+++ PGPLOT.xs
@@ -8,6 +8,8 @@
 
 */
 
+#define PERL_POLLUTE
+
 #include "EXTERN.h"   /* std perl include */
 #include "perl.h"     /* std perl include */
 #include "XSUB.h"     /* XSUB include */
