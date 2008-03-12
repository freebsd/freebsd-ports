Index: qemu/hw/e1000.c
===================================================================
RCS file: /sources/qemu/qemu/hw/e1000.c,v
retrieving revision 1.3
retrieving revision 1.4
diff -u -p -r1.3 -r1.4
--- hw/e1000.c	10 Feb 2008 13:34:48 -0000	1.3
+++ hw/e1000.c	10 Mar 2008 00:02:10 -0000	1.4
@@ -50,7 +50,7 @@ static int debugflags = DBGBIT(TXERR) | 
 #endif
 
 #define IOPORT_SIZE       0x40
-#define PNPMMIO_SIZE      0x60000
+#define PNPMMIO_SIZE      0x20000
 
 /*
  * HW models:
