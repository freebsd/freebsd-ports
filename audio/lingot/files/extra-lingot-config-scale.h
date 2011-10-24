--- src/lingot-config-scale.h.orig	2011-10-18 06:29:18.000000000 +0200
+++ src/lingot-config-scale.h	2011-10-18 06:30:42.000000000 +0200
@@ -23,6 +23,11 @@
 #ifndef LINGOT_CONFIG_SCALE_H_
 #define LINGOT_CONFIG_SCALE_H_
 
+/* FreeBSD patch for log2 */
+#ifdef __FreeBSD__
+#define log2(x) (log(x) / M_LN2)
+#endif /* __FreeBSD__ */
+
 #include "lingot-defs.h"
 
 typedef struct _LingotScale LingotScale;
