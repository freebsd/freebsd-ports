--- firmware/fx2/common/spi.c.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/spi.c	2012-10-07 19:39:17.000000000 -0500
@@ -98,17 +98,17 @@
 write_byte_msb (unsigned char v);
 
 static void
-write_bytes_msb (const xdata unsigned char *buf, unsigned char len);
+write_bytes_msb (const __xdata unsigned char *buf, unsigned char len);
 
 static void
-read_bytes_msb (xdata unsigned char *buf, unsigned char len);
+read_bytes_msb (__xdata unsigned char *buf, unsigned char len);
 
   
 // returns non-zero if successful, else 0
 unsigned char
 spi_read (unsigned char header_hi, unsigned char header_lo,
 	  unsigned char enables, unsigned char format,
-	  xdata unsigned char *buf, unsigned char len)
+	  __xdata unsigned char *buf, unsigned char len)
 {
   if (count_bits8 (enables) > 1)
     return 0;		// error, too many enables set
@@ -165,7 +165,7 @@
 unsigned char
 spi_write (unsigned char header_hi, unsigned char header_lo,
 	   unsigned char enables, unsigned char format,
-	   const xdata unsigned char *buf, unsigned char len)
+	   const __xdata unsigned char *buf, unsigned char len)
 {
   setup_enables (enables);
 
@@ -261,7 +261,7 @@
 }
 
 static void
-write_bytes_msb (const xdata unsigned char *buf, unsigned char len)
+write_bytes_msb (const __xdata unsigned char *buf, unsigned char len)
 {
   while (len-- != 0){
     write_byte_msb (*buf++);
@@ -320,9 +320,10 @@
 }
 #else
 static unsigned char
-read_byte_msb (void) _naked
+read_byte_msb (void)
+// _naked
 {
-  _asm
+  __asm
 	clr	a
 
 	setb	_bitS_CLK
@@ -367,12 +368,12 @@
 
 	mov	dpl,a
 	ret
-  _endasm;
+  __endasm;
 }
 #endif
 
 static void
-read_bytes_msb (xdata unsigned char *buf, unsigned char len)
+read_bytes_msb (__xdata unsigned char *buf, unsigned char len)
 {
   while (len-- != 0){
     *buf++ = read_byte_msb ();
