--- rdjpgcom.c.orig	2009-04-03 01:30:13.000000000 +0200
+++ rdjpgcom.c	2009-06-30 13:49:16.000000000 +0200
@@ -124,6 +124,7 @@
 #define M_EOI   0xD9		/* End Of Image (end of datastream) */
 #define M_SOS   0xDA		/* Start Of Scan (begins compressed data) */
 #define M_APP0	0xE0		/* Application-specific marker, type N */
+#define M_APP1  0xE1		/* Typically EXIF marker */
 #define M_APP12	0xEC		/* (we don't bother to list all 16 APPn's) */
 #define M_COM   0xFE		/* COMment */
 
@@ -214,6 +215,175 @@
   }
 }
 
+/*
+ * Helper routine to skip the given number of bytes.
+ */
+
+static void
+skip_n (unsigned int length)
+{
+  while (length > 0) {
+    (void) read_1_byte();
+    length--;
+  }
+}
+
+/*
+ * Parses an APP1 marker looking for EXIF data. If EXIF, the orientation is
+ * reported to stdout.
+ */
+
+static void
+process_APP1 (void)
+{
+  unsigned int length, i;
+  int is_motorola; /* byte order indicator */
+  unsigned int offset, number_of_tags, tagnum;
+  int orientation;
+  char *ostr;
+  /* This 64K buffer would probably be best if allocated dynamically, but it's
+   * the only one on this program so it's really not that
+   * important. Allocating on the stack is not an option, as 64K might be too
+   * big for some (crippled) platforms. */
+  static unsigned char exif_data[65536L];
+
+  /* Get the marker parameter length count */
+  length = read_2_bytes();
+  /* Length includes itself, so must be at least 2 */
+  if (length < 2)
+    ERREXIT("Erroneous JPEG marker length");
+  length -= 2;
+
+  /* We only care if APP1 is really an EXIF marker. Minimum length is 6 for
+   * signature plus 12 for an IFD. */
+  if (length < 18) {
+    skip_n(length);
+    return;
+  }
+
+  /* Check for actual EXIF marker */
+  for (i=0; i < 6; i++)
+    exif_data[i] = (unsigned char) read_1_byte();
+  length -= 6;
+  if (exif_data[0] != 0x45 ||
+      exif_data[1] != 0x78 ||
+      exif_data[2] != 0x69 ||
+      exif_data[3] != 0x66 ||
+      exif_data[4] != 0 ||
+      exif_data[5] != 0) {
+    skip_n(length);
+    return;
+  }
+
+  /* Read all EXIF body */
+  for (i=0; i < length; i++)
+    exif_data[i] = (unsigned char) read_1_byte();
+
+  /* Discover byte order */
+  if (exif_data[0] == 0x49 && exif_data[1] == 0x49)
+    is_motorola = 0;
+  else if (exif_data[0] == 0x4D && exif_data[1] == 0x4D)
+    is_motorola = 1;
+  else
+    return;
+
+  /* Check Tag Mark */
+  if (is_motorola) {
+    if (exif_data[2] != 0) return;
+    if (exif_data[3] != 0x2A) return;
+  } else {
+    if (exif_data[3] != 0) return;
+    if (exif_data[2] != 0x2A) return;
+  }
+
+  /* Get first IFD offset (offset to IFD0) */
+  if (is_motorola) {
+    if (exif_data[4] != 0) return;
+    if (exif_data[5] != 0) return;
+    offset = exif_data[6];
+    offset <<= 8;
+    offset += exif_data[7];
+  } else {
+    if (exif_data[7] != 0) return;
+    if (exif_data[6] != 0) return;
+    offset = exif_data[5];
+    offset <<= 8;
+    offset += exif_data[4];
+  }
+  if (offset > length - 2) return; /* check end of data segment */
+
+  /* Get the number of directory entries contained in this IFD */
+  if (is_motorola) {
+    number_of_tags = exif_data[offset];
+    number_of_tags <<= 8;
+    number_of_tags += exif_data[offset+1];
+  } else {
+    number_of_tags = exif_data[offset+1];
+    number_of_tags <<= 8;
+    number_of_tags += exif_data[offset];
+  }
+  if (number_of_tags == 0) return;
+  offset += 2;
+
+  /* Search for Orientation Tag in IFD0 */
+  for (;;) {
+    if (offset > length - 12) return; /* check end of data segment */
+    /* Get Tag number */
+    if (is_motorola) {
+      tagnum = exif_data[offset];
+      tagnum <<= 8;
+      tagnum += exif_data[offset+1];
+    } else {
+      tagnum = exif_data[offset+1];
+      tagnum <<= 8;
+      tagnum += exif_data[offset];
+    }
+    if (tagnum == 0x0112) break; /* found Orientation Tag */
+    if (--number_of_tags == 0) return;
+    offset += 12;
+  }
+
+  /* Get the Orientation value */
+  if (is_motorola) {
+    if (exif_data[offset+8] != 0) return;
+    orientation = exif_data[offset+9];
+  } else {
+    if (exif_data[offset+9] != 0) return;
+    orientation = exif_data[offset+8];
+  }
+  if (orientation == 0 || orientation > 8) return;
+
+  /* Print the orientation (position of the 0th row - 0th column) */
+  switch (orientation) {
+  case 1:
+    ostr = "top-left";
+    break;
+  case 2:
+    ostr = "top-right";
+    break;
+  case 3:
+    ostr = "bottom-right";
+    break;
+  case 4:
+    ostr = "bottom-left";
+    break;
+  case 5:
+    ostr = "left-top";
+    break;
+  case 6:
+    ostr = "right-top";
+    break;
+  case 7:
+    ostr = "right-bottom";
+    break;
+  case 8:
+    ostr = "left-bottom";
+    break;
+  default:
+    return;
+  }
+  printf("EXIF orientation: %s\n",ostr);
+}
 
 /*
  * Process a COM marker.
@@ -381,6 +551,15 @@
       process_COM(raw);
       break;
 
+    case M_APP1:
+      /* APP1 is usually the EXIF marker used by digital cameras, attempt to
+       * process it to give some useful info. */
+      if (verbose) {
+        process_APP1();
+      } else
+        skip_variable();
+      break;
+
     case M_APP12:
       /* Some digital camera makers put useful textual information into
        * APP12 markers, so we print those out too when in -verbose mode.
