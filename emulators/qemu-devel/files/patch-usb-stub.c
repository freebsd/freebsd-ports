Index: qemu/usb-stub.c
@@ -1,4 +1,6 @@
-#include "vl.h"
+#include "qemu-common.h"
+#include "console.h"
+#include "hw/usb.h"
 
 void usb_host_info(void)
 {
