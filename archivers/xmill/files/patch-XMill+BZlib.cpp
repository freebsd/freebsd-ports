--- XMill/BZlib.cpp.orig	2008-07-26 04:10:15.000000000 +0700
+++ XMill/BZlib.cpp	2008-07-26 04:20:22.000000000 +0700
@@ -44,7 +44,7 @@
 
 void BZip::initCompress() 
 {
-	if(bzCompressInit(&bzstate,7,0,0) != BZ_OK)	{
+	if(BZ2_bzCompressInit(&bzstate,7,0,0) != BZ_OK)	{
 		throw new XMillException (XMILL_ERR_ZLIB, "Error while compressing container!");
 	}
 }
@@ -60,19 +60,19 @@
 {
 	if (flag == -1)
 		flag = BZ_FINISH;
-	return bzCompress(&bzstate,flag);
+	return BZ2_bzCompress(&bzstate,flag);
 }
 
 void BZip::endCompress() 
 {
-	if(bzCompressEnd(&bzstate) != BZ_OK) {
+	if(BZ2_bzCompressEnd(&bzstate) != BZ_OK) {
 		throw new XMillException (XMILL_ERR_ZLIB, "Error while compressing container!");
 	}
 }
 
 void BZip::initUncompress() 
 {
-	if(bzDecompressInit(&bzstate,0,0) != BZ_OK) {
+	if(BZ2_bzDecompressInit(&bzstate,0,0) != BZ_OK) {
 		throw new XMillException (XMILL_ERR_ZLIB, "Error while uncompressing container!");
 	}
 }
@@ -106,7 +106,7 @@
 
 void BZip::endUncompress()
 {
-	if(bzDecompressEnd(&bzstate) != BZ_OK) {
+	if(BZ2_bzDecompressEnd(&bzstate) != BZ_OK) {
 		throw new XMillException (XMILL_ERR_ZLIB, "Error while uncompressing container!");
 	}
 }
@@ -138,22 +138,24 @@
 
 int BZip::getTotalOut()
 {
-	return bzstate.total_out;
+	return bzstate.total_out_lo32;
 }
 
 int BZip::getTotalIn()
 {
-	return bzstate.total_in;
+	return bzstate.total_in_lo32;
 }
 
 void BZip::resetTotals()
 {
-	bzstate.total_in = 0;
-	bzstate.total_out = 0;
+	bzstate.total_in_lo32 = 0;
+	bzstate.total_in_hi32 = 0;
+	bzstate.total_out_lo32 = 0;
+	bzstate.total_out_hi32 = 0;
 }
 
 int BZip::doUncompress()
 {
-	return bzDecompress(&bzstate);
+	return BZ2_bzDecompress(&bzstate);
 }
 
