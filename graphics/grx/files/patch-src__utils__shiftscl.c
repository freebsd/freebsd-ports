--- src/utils/shiftscl.c.orig
+++ src/utils/shiftscl.c
@@ -34,7 +34,7 @@
     for (plane = 0; plane < planes; ++plane) {
       GR_int8u far *s = *(src++) + ws;
       GR_int8u far *d = *(dst++) + ws;
-#     if defined(__GNUC__) && defined(__i386__)
+#     if defined(__GNUC__) && defined(__i386__) && !defined(__clang__)
 	int _dummy_, w = ws;
 	/* sad but true: the x86 bytesex forces this inefficient code :( */
 	asm volatile ("\n"
@@ -91,7 +91,7 @@
     for (plane = 0; plane < planes; ++plane) {
       GR_int8u far *s = *(src++);
       GR_int8u far *d = *(dst++);
-#     if defined(__GNUC__) && defined(__i386__)
+#     if defined(__GNUC__) && defined(__i386__) && !defined(__clang__)
 	int _dummy_, w = ws;
 	asm volatile ("\n"
 	  "   movb    (%0),%%ch    \n"
