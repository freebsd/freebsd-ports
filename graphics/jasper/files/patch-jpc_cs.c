--- src/libjasper/jpc/jpc_cs.c.orig	Fri Jan 19 21:43:07 2007
+++ src/libjasper/jpc/jpc_cs.c	Wed Feb  7 11:05:57 2007
@@ -288,7 +288,7 @@
 			jpc_ms_dump(ms, stderr);
 		}
 
-		if (JAS_CAST(ulong, jas_stream_tell(tmpstream)) != ms->len) {
+		if (JAS_CAST(unsigned long, jas_stream_tell(tmpstream)) != ms->len) {
 			jas_eprintf("warning: trailing garbage in marker segment (%ld bytes)\n",
 			  ms->len - jas_stream_tell(tmpstream));
 		}
