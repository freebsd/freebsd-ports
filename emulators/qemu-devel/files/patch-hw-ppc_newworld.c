--- a/hw/ppc/mac_newworld.c
+++ b/hw/ppc/mac_newworld.c
@@ -68,6 +68,11 @@
 #include "hw/usb.h"
 #include "blockdev.h"
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 #define MAX_IDE_BUS 2
 #define CFG_ADDR 0xf0000510
 
