--- libvisual/lv_cpu.c.orig	Sun Mar 20 20:17:51 2005
+++ libvisual/lv_cpu.c	Sun Mar 20 20:18:19 2005
@@ -65,6 +65,9 @@
 #include "lv_log.h"
 #include "lv_cpu.h"
 
+/* stolen from 5.3-stable's unistd.h */
+#define		_SC_NPROCESSORS_ONLN	58
+
 static VisCPU _lv_cpu_caps;
 static int _lv_cpu_initialized = FALSE;
 
