
$FreeBSD$

--- src/libjasper/jpc/jpc_cs.c	2003/05/07 16:24:56	1.1
+++ src/libjasper/jpc/jpc_cs.c	2003/05/07 16:25:31
@@ -337,7 +337,7 @@
 			jpc_ms_dump(ms, stderr);
 		}
 
-		if (JAS_CAST(ulong, jas_stream_tell(tmpstream)) != ms->len) {
+		if (JAS_CAST(unsigned long, jas_stream_tell(tmpstream)) != ms->len) {
 			fprintf(stderr,
 			  "warning: trailing garbage in marker segment (%ld bytes)\n",
 			  ms->len - jas_stream_tell(tmpstream));
