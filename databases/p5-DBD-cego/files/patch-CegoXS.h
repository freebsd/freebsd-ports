--- CegoXS.h.orig	2010-11-21 09:25:27.000000000 +0800
+++ CegoXS.h	2011-05-29 21:11:15.361979766 +0800
@@ -9,4 +9,16 @@
 #include "dbdimp.h"
 #include <dbd_xsh.h>
 
+#ifndef sv_yes
+#define sv_yes PL_sv_yes
+#endif
+
+#ifndef sv_no
+#define sv_no PL_sv_no
+#endif
+
+#ifndef dirty
+#define dirty PL_dirty
+#endif
+
 #endif
