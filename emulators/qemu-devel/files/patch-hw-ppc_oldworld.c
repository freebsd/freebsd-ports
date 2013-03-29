--- a/hw/ppc/mac_oldworld.c
+++ b/hw/ppc/mac_oldworld.c
@@ -47,6 +47,11 @@
 #define MAX_IDE_BUS 2
 #define CFG_ADDR 0xf0000510
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 static int fw_cfg_boot_set(void *opaque, const char *boot_device)
 {
     fw_cfg_add_i16(opaque, FW_CFG_BOOT_DEVICE, boot_device[0]);
