--- jerror.h.orig	Sat Oct 18 14:59:10 1997
+++ jerror.h	Fri Jun  4 15:20:23 2004
@@ -45,8 +45,11 @@
 JMESSAGE(JERR_BAD_ALLOC_CHUNK, "MAX_ALLOC_CHUNK is wrong, please fix")
 JMESSAGE(JERR_BAD_BUFFER_MODE, "Bogus buffer control mode")
 JMESSAGE(JERR_BAD_COMPONENT_ID, "Invalid component ID %d in SOS")
+JMESSAGE(JERR_BAD_CROP_SPEC, "Invalid crop request")
 JMESSAGE(JERR_BAD_DCT_COEF, "DCT coefficient out of range")
 JMESSAGE(JERR_BAD_DCTSIZE, "IDCT output block size %d not supported")
+JMESSAGE(JERR_BAD_DROP_SAMPLING,
+        "Component index %d: mismatching sampling ratio %d:%d, %d:%d, %c")
 JMESSAGE(JERR_BAD_HUFF_TABLE, "Bogus Huffman table definition")
 JMESSAGE(JERR_BAD_IN_COLORSPACE, "Bogus input colorspace")
 JMESSAGE(JERR_BAD_J_COLORSPACE, "Bogus JPEG colorspace")
@@ -226,6 +229,15 @@
    (cinfo)->err->msg_parm.i[1] = (p2), \
    (cinfo)->err->msg_parm.i[2] = (p3), \
    (cinfo)->err->msg_parm.i[3] = (p4), \
+   (*(cinfo)->err->error_exit) ((j_common_ptr) (cinfo)))
+#define ERREXIT6(cinfo,code,p1,p2,p3,p4,p5,p6)  \
+  ((cinfo)->err->msg_code = (code), \
+   (cinfo)->err->msg_parm.i[0] = (p1), \
+   (cinfo)->err->msg_parm.i[1] = (p2), \
+   (cinfo)->err->msg_parm.i[2] = (p3), \
+   (cinfo)->err->msg_parm.i[3] = (p4), \
+   (cinfo)->err->msg_parm.i[4] = (p5), \
+   (cinfo)->err->msg_parm.i[5] = (p6), \
    (*(cinfo)->err->error_exit) ((j_common_ptr) (cinfo)))
 #define ERREXITS(cinfo,code,str)  \
   ((cinfo)->err->msg_code = (code), \
