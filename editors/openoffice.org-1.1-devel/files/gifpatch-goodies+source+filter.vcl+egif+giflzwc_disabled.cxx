--- /dev/null	1970-01-01 01:00:00.000000000 +0100
+++ ../goodies/source/filter.vcl/egif/giflzwc_disabled.cxx	2002-08-15 15:09:47.000000000 +0200
@@ -0,0 +1,42 @@
+/**********************************
+ * This code is copied from giflzwc.cxx, with the patented LZW compression code removed.
+ **********************************/ 
+
+//#include <tools/stream.hxx>
+#include "giflzwc.hxx"
+
+// --------------------
+// - GIFLZWCompressor -
+// --------------------
+
+GIFLZWCompressor::GIFLZWCompressor()
+{
+	pIDOS=NULL;
+}
+
+// ------------------------------------------------------------------------
+
+GIFLZWCompressor::~GIFLZWCompressor()
+{
+}
+
+// ------------------------------------------------------------------------
+
+void GIFLZWCompressor::StartCompression( SvStream& rGIF, USHORT nPixelSize )
+{
+	/********************** DISABLED *************************/
+}
+
+// ------------------------------------------------------------------------
+
+void GIFLZWCompressor::Compress( HPBYTE pSrc, ULONG nSize )
+{
+	/********************** DISABLED *************************/
+}
+
+// ------------------------------------------------------------------------
+
+void GIFLZWCompressor::EndCompression()
+{
+	/********************** DISABLED *************************/
+}
