--- libg19.h.orig	2010-04-12 21:56:18.000000000 +0200
+++ libg19.h	2011-04-16 08:25:58.000000000 +0200
@@ -20,15 +20,21 @@
 #define G19_H
 
 #include <stdint.h>
+#include <string.h>
 
 #ifdef __cplusplus
 extern "C"
 {
 #endif
 
-#define LIBG19_VERSION "1.1.1"
+#define LIBG19_VERSION_MAJOR	1
+#define LIBG19_VERSION_MINOR	2
+#define LIBG19_VERSION_MICRO	0
+
+#define LIBG19_VERSION			"1.2.0"
 
 #define G19_BMP_SIZE	154112
+#define G19_BMP_DSIZE	153600
 
 typedef struct
 {
@@ -38,7 +44,32 @@
 }
 G19Device;
 
-enum
+enum G19UpdateFlags
+{
+	/*
+	 * Flags the screen to be
+	 * used and as of right now
+	 * there is only one which is
+	 * the G19.
+	 */
+	G19_SCREEN_DEFAULT	= 1 << 0,
+	
+	/* Flags to prepend header data */
+	G19_PREPEND_HDATA	= 1 << 1,
+	
+	/* Flags not to parse the data
+	 * and format it
+	 */
+	G19_DATA_TYPE_RAW	= 1 << 2,
+	
+	/* Flags to format a bitmap with
+	 * with just bitmap data that has
+	 * 4 bytes per pixel. (RGBA)
+	 */
+	G19_DATA_TYPE_BMP	= 1 << 3
+};
+
+enum G19Keys
 {
 	G19_KEY_G1			= 1 << 0,
 	G19_KEY_G2			= 1 << 1,
@@ -104,19 +135,9 @@
  * Sends raw data to the lcd without formatting
  * 
  * @param data pointer to the screen data
- * @param len amount of data to be written in bytes
- **/
-void g19_update_lcd(unsigned char * data, int len);
-
-/**
- * Prepends the header data to the screen data
- * Formats the bitmap data
- * Writes the result to the screen
- * 
- * @param data pointer to the bitmap data
- * @param len amount of data to be written in bytes
+ * @param size size of the data to be written in bytes
  **/
-void g19_update_lcd_bmp(unsigned char * data, int len);
+void g19_update_lcd(unsigned char * data, size_t size, unsigned int flags);
 
 /**
  * Sets the backlighting color
@@ -127,7 +148,7 @@
  * 
  * @return non zero on error
  **/
-int g19_set_backlight(int r, int g, int b);
+int g19_set_backlight(unsigned char r, unsigned char g, unsigned char b);
 
 /**
  * Sets the M-Key lights
