--- platforms/Cross/plugins/JPEGReadWriter2Plugin/jmemdatasrc.c.orig	Thu May 13 16:25:49 2004
+++ platforms/Cross/plugins/JPEGReadWriter2Plugin/jmemdatasrc.c	Thu May 13 16:25:58 2004
@@ -198,4 +198,5 @@
   src->actualPos = pSourceData + offset;
 
   return((src->actualPos + src->bytesLeft) == (pSourceData + sourceDataSize));
-}
\ No newline at end of file
+}
+
