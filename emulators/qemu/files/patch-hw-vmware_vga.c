Index: qemu/hw/vmware_vga.c
@@ -28,9 +28,9 @@
 #define VERBOSE
 #define EMBED_STDVGA
 #undef DIRECT_VRAM
-#define HW_RECT_ACCEL
-#define HW_FILL_ACCEL
-#define HW_MOUSE_ACCEL
+/* #define HW_RECT_ACCEL */
+/* #define HW_FILL_ACCEL */
+/* #define HW_MOUSE_ACCEL */
 
 #ifdef EMBED_STDVGA
 # include "vga_int.h"
@@ -76,6 +76,7 @@
     uint32_t wblue;
     int syncing;
     int fb_size;
+    int empty;
 
     union {
         uint32_t *fifo;
@@ -487,7 +488,7 @@
 
 static inline int vmsvga_fifo_empty(struct vmsvga_state_s *s)
 {
-    if (!s->config || !s->enable)
+    if (!s->config || !s->enable || s->empty)
         return 1;
     return (s->cmd->next_cmd == s->cmd->stop);
 }
@@ -495,6 +496,10 @@
 static inline uint32_t vmsvga_fifo_read_raw(struct vmsvga_state_s *s)
 {
     uint32_t cmd = s->fifo[CMD(stop) >> 2];
+    if (s->cmd->next_cmd == s->cmd->stop) {
+        s->empty = 1;
+        return 0;
+    }
     s->cmd->stop = cpu_to_le32(CMD(stop) + 4);
     if (CMD(stop) >= CMD(max))
         s->cmd->stop = s->cmd->min;
@@ -512,6 +517,7 @@
     int args = 0;
     int x, y, dx, dy, width, height;
     struct vmsvga_cursor_definition_s cursor;
+    s->empty = 0;
     while (!vmsvga_fifo_empty(s))
         switch (cmd = vmsvga_fifo_read(s)) {
         case SVGA_CMD_UPDATE:
@@ -533,6 +539,7 @@
             vmsvga_fill_rect(s, colour, x, y, width, height);
             break;
 #else
+            args = 0;
             goto badcmd;
 #endif
 
@@ -547,6 +554,7 @@
             vmsvga_copy_rect(s, x, y, dx, dy, width, height);
             break;
 #else
+            args = 0;
             goto badcmd;
 #endif
 
@@ -609,6 +617,7 @@
             break; /* Nop */
 
         default:
+            args = 0;
         badcmd:
             while (args --)
                 vmsvga_fifo_read(s);
