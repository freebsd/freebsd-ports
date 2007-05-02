Index: qemu/hw/vmware_vga.c
@@ -26,8 +26,8 @@
 #define VERBOSE
 #define EMBED_STDVGA
 #undef DIRECT_VRAM
-#define HW_RECT_ACCEL
-#define HW_FILL_ACCEL
+/* #define HW_RECT_ACCEL */
+/* #define HW_FILL_ACCEL */
 #define HW_MOUSE_ACCEL
 
 #ifdef EMBED_STDVGA
