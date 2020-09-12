Obtained from:	https://github.com/OSGeo/gdal/commit/e236eeaed1be45a4af457565085e3db1f2fc489f

--- frmts/jpeg2000/jpeg2000_vsil_io.cpp.orig	2020-05-04 09:21:31 UTC
+++ frmts/jpeg2000/jpeg2000_vsil_io.cpp
@@ -94,13 +94,23 @@ typedef struct {
 * File stream object.
 \******************************************************************************/
 
+// PRIjas_seqent macro is defined since Jasper 2.0.17
+
+#ifndef PRIjas_seqent
 static int JPEG2000_VSIL_read(jas_stream_obj_t *obj, char *buf, int cnt)
+#else
+static int JPEG2000_VSIL_read(jas_stream_obj_t *obj, char *buf, unsigned cnt)
+#endif
 {
     jas_stream_VSIFL_t *fileobj = JAS_CAST(jas_stream_VSIFL_t *, obj);
     return static_cast<int>(VSIFReadL(buf, 1, cnt, fileobj->fp));
 }
 
+#ifndef PRIjas_seqent
 static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, char *buf, int cnt)
+#else
+static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, const char *buf, unsigned int cnt)
+#endif
 {
     jas_stream_VSIFL_t *fileobj = JAS_CAST(jas_stream_VSIFL_t *, obj);
     return static_cast<int>(VSIFWriteL(buf, 1, cnt, fileobj->fp));
