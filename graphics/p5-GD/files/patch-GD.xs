--- GD.xs.orig	Thu Apr 24 07:00:11 2003
+++ GD.xs	Wed May 14 17:33:13 2003
@@ -18,6 +18,30 @@
 /* Copyright 1995 - 1998, Lincoln D. Stein.  See accompanying README file for
 	usage restrictions */
 
+#ifndef PERL_REVISION
+#   ifndef __PATCHLEVEL_H_INCLUDED__
+#       include "patchlevel.h"
+#   endif
+#   ifndef PERL_REVISION
+#       define PERL_REVISION    (5)
+        /* Replace: 1 */
+#       define PERL_VERSION     PATCHLEVEL
+#       define PERL_SUBVERSION  SUBVERSION
+        /* Replace PERL_PATCHLEVEL with PERL_VERSION */
+        /* Replace: 0 */
+#   endif
+#endif
+
+#if (PERL_VERSION == 5) && (PERL_SUBVERSION==3)
+#ifndef PL_na
+# define PL_na na
+#endif
+
+#ifndef SvPV_nolen
+# define SvPV_nolen(sv) SvPV(sv, PL_na)
+#endif
+#endif /* 5.00503 */
+
 static int
 not_here(char *s)
 {
