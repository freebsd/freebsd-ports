--- CegoXS.h.orig	2010-11-21 01:25:27 UTC
+++ CegoXS.h
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
