--- frmts/jpeg2000/jpeg2000_vsil_io.cpp.orig	2020-09-01 08:39:25 UTC
+++ frmts/jpeg2000/jpeg2000_vsil_io.cpp
@@ -109,7 +109,7 @@ static int JPEG2000_VSIL_read(jas_stream_obj_t *obj, c
 #ifndef PRIjas_seqent
 static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, char *buf, int cnt)
 #else
-static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, char *buf, unsigned int cnt)
+static int JPEG2000_VSIL_write(jas_stream_obj_t *obj, const char *buf, unsigned int cnt)
 #endif
 {
     jas_stream_VSIFL_t *fileobj = JAS_CAST(jas_stream_VSIFL_t *, obj);
