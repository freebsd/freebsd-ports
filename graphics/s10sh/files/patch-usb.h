--- usb.h.orig	Tue Mar 13 06:46:18 2001
+++ usb.h	Sat Dec  7 06:16:19 2002
@@ -19,15 +19,20 @@
 #define USB_INIT_S20            2       /* S20 found */
 #define USB_INIT_S100		3	/* S100 (Digital Ixus) found */
 #define USB_INIT_G1		4	/* G1 found */
+#define USB_INIT_A20		5	/* A20 found */
+#define USB_INIT_G2		6	/* G2 found */
+#define USB_INIT_G3		7	/* G3 found */
 #define USB_INIT_NEW		100	/* Unsupported PowerShot found! */
 #define USB_INIT_FAILED         -1      /* Unable to initialize USB */
 
 #define VENDOR_ID_CANON         0x04A9
 #define PRODUCT_ID_S10          0x3041	/* PowerShot S10 */
 #define PRODUCT_ID_S20          0x3043	/* PowerShot S20 */
+#define PRODUCT_ID_A20		0x304E  /* PowerShot A20 */
 #define PRODUCT_ID_S100_US	0x3045	/* S100, aka. Digital Ixus, Elph */
 #define PRODUCT_ID_S100_EU	0x3047	/* S100, aka. Digital Ixus, Elph */
 #define PRODUCT_ID_G1		0x3048	/* PowerShot G1 */
+#define PRODUCT_ID_G3		0x306E
 
 /* The Canon USB protocol of the S10, S20, S100, G1 is the same.
  * We can hope that the next cameras will adopt a compatible protocol
