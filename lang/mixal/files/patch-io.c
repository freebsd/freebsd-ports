--- io.c.orig	Mon Jun  3 17:56:10 2002
+++ io.c	Mon Jun  3 18:00:59 2002
@@ -19,9 +19,12 @@
 } device_table[] = {
     {tape}, {tape}, {tape}, {tape}, {tape}, {tape}, {tape}, {tape}, 
     {disk}, {disk}, {disk}, {disk}, {disk}, {disk}, {disk}, {disk}, 
-    {card_in, stdin},
-    {card_out, stdout},
-    {printer, stdout},
+    {card_in, 0}, /* was stdin */
+#define PATCH_CARD_IN 16
+    {card_out, 0}, /* was stdout */
+#define PATCH_CARD_OUT 17
+    {printer, 0}, /* was stdout */
+#define PATCH_PRINTER 18
     {console}
 };
 
@@ -54,6 +57,13 @@
 /* console */   {  14, console_in, console_out, console_ioc }
 
 };
+
+void initialize_io(void)
+{
+    device_table[PATCH_CARD_IN].file = stdin;
+    device_table[PATCH_CARD_OUT].file = stdout;
+    device_table[PATCH_PRINTER].file = stdout;
+}
 
 static unsigned block_size(unsigned device)
 {
