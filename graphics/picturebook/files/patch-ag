--- ../picturebook.old/sonypi.c	Mon Dec 25 19:01:43 2000
+++ sonypi.c	Mon Dec 25 19:03:23 2000
@@ -72,7 +72,7 @@
 #define MUTE_V2 0x29
 
 static int spic_fd;
-
+#ifdef LINUX
 static void OUTB(u8 v, int port)
 {
 	outb(v, port);
@@ -83,7 +83,42 @@
 	usleep(10);
 	return inb(port);
 }
+#define OUTW outw
+#else ifdef __FreeBSD__
+#include <machine/cpufunc.h>
+static void OUTB(u8 v, unsigned int port)
+{
+	outb(port,v);
+}
+static void OUTW(u16 v, unsigned int port)
+{
+	outw(port,v);
+}
+
+static u8 INB(unsigned int port)
+{
+	usleep(10);
+	return inb(port);
+}
+static int deviofd=-1;
+static int iopl(int lvl)
+{
+  if(lvl==0){
+    if(deviofd!=-1){
+      close(deviofd);
+      deviofd=-1;
+    }    
+    return 0;
+  }else if(lvl==3){
+    if(deviofd==-1){
+      deviofd=open("/dev/io",0);
+    }
+    return deviofd;
+  }
+  return -1;
+}
 
+#endif
 /* initialise the SPIC - this comes from the AML code in the ACPI bios */
 static void spic_srs(int fd, u16 port1, u16 port2, u8 irq)
 {
@@ -98,7 +133,7 @@
 	v2 = inw(SPI_IRQ_PORT);
 	v2 &= ~(0x3 << SPI_IRQ_SHIFT);
 	v2 |= (irq << SPI_IRQ_SHIFT);
-	outw(v2, SPI_IRQ_PORT);
+	OUTW(v2, SPI_IRQ_PORT);
 
 	pci_config_read_u8(fd, SPI_G10L, &v);
 	v = (v & 0x1F) | 0xC0;
@@ -116,7 +151,7 @@
 
 	v = inw(SPI_IRQ_PORT);
 	v |= (0x3 << SPI_IRQ_SHIFT);
-	outw(v, SPI_IRQ_PORT);
+	OUTW(v, SPI_IRQ_PORT);
 	close(spic_fd);
 }
 
@@ -144,10 +179,10 @@
 	u8 v1;
 
 	while (INB(SPIC_PORT2) & 2) ;
-	outb(dev, SPIC_PORT2);
+	OUTB(dev, SPIC_PORT2);
 
 	while (INB(SPIC_PORT2) & 2) ;
-	outb(fn, SPIC_PORT1);
+	OUTB(fn, SPIC_PORT1);
 
 	v1 = INB(SPIC_PORT1);
 	if (debug)
@@ -160,13 +195,13 @@
 	u8 v1;
 
 	while (INB(SPIC_PORT2) & 2) ;
-	outb(dev, SPIC_PORT2);
+	OUTB(dev, SPIC_PORT2);
 
 	while (INB(SPIC_PORT2) & 2) ;
-	outb(fn, SPIC_PORT1);
+	OUTB(fn, SPIC_PORT1);
 
 	while (INB(SPIC_PORT2) & 2) ;
-	outb(v, SPIC_PORT1);
+	OUTB(v, SPIC_PORT1);
 
 	v1 = INB(SPIC_PORT1);
 	if (debug)
@@ -259,7 +294,7 @@
 	v1 = inb(SPIC_PORT1);
 	v2 = inb(SPIC_PORT2);
 	if ((v2 & 0x10) == 0 || v1 == 0) return 0;
-	/* the following clears the event bits */
+	/* the following clears the evnet bits */
 	spic_call2(0x81, 0xff);
 	return (signed char)v1;
 }
@@ -292,96 +327,96 @@
 void spic_setup_vga(void)
 {
 /* :about to start capture again */
-outb(0x09, 0x03CE); usleep(10);
+OUTB(0x09, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000026 */
-outw(0x2609, 0x03CE); usleep(10);
-outb(0x0A, 0x03CE); usleep(10);
+OUTW(0x2609, 0x03CE); usleep(10);
+OUTB(0x0A, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000021 */
-outw(0x210A, 0x03CE); usleep(10);
-outb(0x08, 0x03C4); usleep(10);
+OUTW(0x210A, 0x03CE); usleep(10);
+OUTB(0x08, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 00000020 */
-outb(0x09, 0x03C4); usleep(10);
+OUTB(0x09, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 000000F3 */
-outw(0x2008, 0x03C4); usleep(10);
-outw(0xF309, 0x03C4); usleep(10);
-outw(0x2609, 0x03CE); usleep(10);
-outw(0x210A, 0x03CE); usleep(10);
-outb(0x09, 0x03CE); usleep(10);
+OUTW(0x2008, 0x03C4); usleep(10);
+OUTW(0xF309, 0x03C4); usleep(10);
+OUTW(0x2609, 0x03CE); usleep(10);
+OUTW(0x210A, 0x03CE); usleep(10);
+OUTB(0x09, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000026 */
-outw(0x2609, 0x03CE); usleep(10);
-outb(0x0A, 0x03CE); usleep(10);
+OUTW(0x2609, 0x03CE); usleep(10);
+OUTB(0x0A, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000021 */
-outw(0x210A, 0x03CE); usleep(10);
-outb(0x08, 0x03C4); usleep(10);
+OUTW(0x210A, 0x03CE); usleep(10);
+OUTB(0x08, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 00000020 */
-outb(0x09, 0x03C4); usleep(10);
+OUTB(0x09, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 000000F3 */
-outw(0xF109, 0x03C4); usleep(10);
-outw(0x2609, 0x03CE); usleep(10);
-outw(0x210A, 0x03CE); usleep(10);
-outb(0x09, 0x03CE); usleep(10);
+OUTW(0xF109, 0x03C4); usleep(10);
+OUTW(0x2609, 0x03CE); usleep(10);
+OUTW(0x210A, 0x03CE); usleep(10);
+OUTB(0x09, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000026 */
-outw(0x2609, 0x03CE); usleep(10);
-outb(0x0A, 0x03CE); usleep(10);
+OUTW(0x2609, 0x03CE); usleep(10);
+OUTB(0x0A, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000021 */
-outw(0x210A, 0x03CE); usleep(10);
-outb(0x08, 0x03C4); usleep(10);
+OUTW(0x210A, 0x03CE); usleep(10);
+OUTB(0x08, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 00000020 */
-outb(0x09, 0x03C4); usleep(10);
+OUTB(0x09, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 0000001F */
-outw(0x1D09, 0x03C4); usleep(10);
-outw(0x2609, 0x03CE); usleep(10);
-outw(0x210A, 0x03CE); usleep(10);
-outb(0x08, 0x03C4); usleep(10);
+OUTW(0x1D09, 0x03C4); usleep(10);
+OUTW(0x2609, 0x03CE); usleep(10);
+OUTW(0x210A, 0x03CE); usleep(10);
+OUTB(0x08, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 00002621 */
-outb(0x09, 0x03C4); usleep(10);
+OUTB(0x09, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 000026E9 */
-outb(0x08, 0x03C4); usleep(10);
+OUTB(0x08, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 00002621 */
-outb(0x09, 0x03C4); usleep(10);
+OUTB(0x09, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 000026F9 */
-outb(0x09, 0x03CE); usleep(10);
+OUTB(0x09, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000026 */
-outb(0x09, 0x03CE); usleep(10);
-outb(0x26, 0x03CF); usleep(10);
-outb(0x0A, 0x03CE); usleep(10);
+OUTB(0x09, 0x03CE); usleep(10);
+OUTB(0x26, 0x03CF); usleep(10);
+OUTB(0x0A, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000021 */
-outb(0x0A, 0x03CE); usleep(10);
-outb(0x21, 0x03CF); usleep(10);
-outb(0x0F, 0x03C4); usleep(10);
+OUTB(0x0A, 0x03CE); usleep(10);
+OUTB(0x21, 0x03CF); usleep(10);
+OUTB(0x0F, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 00000001 */
-outb(0x0F, 0x03C4); usleep(10);
-outb(0x01, 0x03C5); usleep(10);
-outb(0x0F, 0x03C4); usleep(10);
+OUTB(0x0F, 0x03C4); usleep(10);
+OUTB(0x01, 0x03C5); usleep(10);
+OUTB(0x0F, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 00000001 */
-outb(0x0A, 0x03CE); usleep(10);
-outb(0x21, 0x03CF); usleep(10);
-outb(0x09, 0x03CE); usleep(10);
-outb(0x26, 0x03CF); usleep(10);
-outb(0x09, 0x03CE); usleep(10);
+OUTB(0x0A, 0x03CE); usleep(10);
+OUTB(0x21, 0x03CF); usleep(10);
+OUTB(0x09, 0x03CE); usleep(10);
+OUTB(0x26, 0x03CF); usleep(10);
+OUTB(0x09, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000026 */
-outw(0x2609, 0x03CE); usleep(10);
-outb(0xBF, 0x03CE); usleep(10);
+OUTW(0x2609, 0x03CE); usleep(10);
+OUTB(0xBF, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000000 */
-outb(0xA3, 0x03CE); usleep(10);
+OUTB(0xA3, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 0000000C */
-outw(0xBF, 0x03CE); usleep(10);
-outw(0x0CA3, 0x03CE); usleep(10);
-outb(0x09, 0x03CE); usleep(10);
+OUTW(0xBF, 0x03CE); usleep(10);
+OUTW(0x0CA3, 0x03CE); usleep(10);
+OUTB(0x09, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000026 */
-outw(0x2609, 0x03CE); usleep(10);
-outb(0x0A, 0x03CE); usleep(10);
+OUTW(0x2609, 0x03CE); usleep(10);
+OUTB(0x0A, 0x03CE); usleep(10);
 inb(0x03CF); usleep(10); /* -> 00000021 */
-outw(0x210A, 0x03CE); usleep(10);
-outb(0x08, 0x03C4); usleep(10);
+OUTW(0x210A, 0x03CE); usleep(10);
+OUTB(0x08, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 00000021 */
-outb(0x09, 0x03C4); usleep(10);
+OUTB(0x09, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 000000F9 */
-outw(0x2609, 0x03CE); usleep(10);
-outw(0x210A, 0x03CE); usleep(10);
-outb(0x08, 0x03C4); usleep(10);
+OUTW(0x2609, 0x03CE); usleep(10);
+OUTW(0x210A, 0x03CE); usleep(10);
+OUTB(0x08, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 00002621 */
-outb(0x09, 0x03C4); usleep(10);
+OUTB(0x09, 0x03C4); usleep(10);
 inb(0x03C5); usleep(10); /* -> 000026F9 */
 }
 
@@ -434,3 +469,7 @@
 	}
 	spic_dis();
 }
+
+
+
+
