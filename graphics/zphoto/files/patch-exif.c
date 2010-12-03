--- exif.c.orig	2004-06-07 18:58:04.000000000 +0900
+++ exif.c	2010-12-03 21:25:38.562390923 +0900
@@ -33,11 +33,11 @@
     HEADER_OFFSET2 = 8
 };
 
-#define SWAP_ENDIAN_LONG(val) ((unsigned long) ( \
-    (((unsigned long) (val) & (unsigned long) 0x000000ffU) << 24) | \
-    (((unsigned long) (val) & (unsigned long) 0x0000ff00U) <<  8) | \
-    (((unsigned long) (val) & (unsigned long) 0x00ff0000U) >>  8) | \
-    (((unsigned long) (val) & (unsigned long) 0xff000000U) >> 24)))
+#define SWAP_ENDIAN_LONG(val) ((unsigned int) ( \
+    (((unsigned int) (val) & (unsigned int) 0x000000ffU) << 24) | \
+    (((unsigned int) (val) & (unsigned int) 0x0000ff00U) <<  8) | \
+    (((unsigned int) (val) & (unsigned int) 0x00ff0000U) >>  8) | \
+    (((unsigned int) (val) & (unsigned int) 0xff000000U) >> 24)))
 
 #define SWAP_ENDIAN_SHORT(val) ((unsigned short) ( \
     (((unsigned short) (val) & (unsigned short) 0x00ff) << 8) | \
@@ -46,14 +46,14 @@
 static int 
 is_little_endian ()
 {
-    static long retval = -1;
+    static int retval = -1;
 
     if (retval == -1) {
-	long n = 1;
+	int n = 1;
 	char *p = (char *)&n;
 	char x[] = {1, 0, 0, 0};
 
-	assert(sizeof(long) == 4);
+	assert(sizeof(int) == 4);
 	if (memcmp(p, x, 4) == 0) {
 	    retval = 1;
 	} else {
@@ -63,8 +63,8 @@
     return retval;
 }
 
-static unsigned long
-ulong_from_le (unsigned long x)
+static unsigned int
+uint_from_le (unsigned int x)
 {
     if (is_little_endian()) {
 	return x;
@@ -83,8 +83,8 @@
     }
 }
 
-static unsigned long
-ulong_from_be (unsigned long x)
+static unsigned int
+uint_from_be (unsigned int x)
 {
     if (is_little_endian()) {
 	return SWAP_ENDIAN_LONG(x);
@@ -115,7 +115,7 @@
 
 
 static int
-efseek (FILE *stream, long offset, int whence)
+efseek (FILE *stream, int offset, int whence)
 {
     int x = fseek(stream, offset, whence);
     if (x != 0)
@@ -142,16 +142,16 @@
 typedef void	(*TraverseFunc)	 (FILE *fp,
                                   unsigned short tag, 
                                   unsigned short type, 
-                                  unsigned long size, 
-                                  unsigned long value, 
+                                  unsigned int size, 
+                                  unsigned int value, 
                                   void *data);
 
 static void
 get_special_offset (FILE *fp, 
                     unsigned short tag, 
                     unsigned short type, 
-                    unsigned long size, 
-                    unsigned long value, 
+                    unsigned int size, 
+                    unsigned int value, 
                     void *data)
 {
     if (tag == 0x8769) {
@@ -163,12 +163,12 @@
 get_time (FILE *fp, 
           unsigned short tag,
           unsigned short type,
-          unsigned long size, 
-          unsigned long value, 
+          unsigned int size, 
+          unsigned int value, 
           void *data)
 {
     if (tag == 0x9003) {
-        long curpos;
+        int curpos;
         char buf[BUFSIZ];
         struct tm t;
 
@@ -204,16 +204,16 @@
         return ushort_from_be(x);
 }
 
-static unsigned long
-read_ulong (FILE *fp, int le_exif_p)
+static unsigned int
+read_uint (FILE *fp, int le_exif_p)
 {
-    unsigned long x;
+    unsigned int x;
 
-    efread(&x, sizeof(unsigned long), 1, fp);
+    efread(&x, sizeof(unsigned int), 1, fp);
     if (le_exif_p)
-        return ulong_from_le(x);
+        return uint_from_le(x);
     else
-        return ulong_from_be(x);
+        return uint_from_be(x);
 }
 
 static int
@@ -225,12 +225,12 @@
     n = read_ushort(fp, le_exif_p);
     for (i = 0; i < n; i++) {
         unsigned short tag, type;
-        unsigned long size, value;
+        unsigned int size, value;
 
         tag   = read_ushort(fp, le_exif_p);
         type  = read_ushort(fp, le_exif_p);
-        size  = read_ulong(fp, le_exif_p);
-        value = read_ulong(fp, le_exif_p);
+        size  = read_uint(fp, le_exif_p);
+        value = read_uint(fp, le_exif_p);
 
         func(fp, tag, type, size, value, data);
     }
