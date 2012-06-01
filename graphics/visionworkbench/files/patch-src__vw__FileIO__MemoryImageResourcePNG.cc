--- src/vw/FileIO/MemoryImageResourcePNG.cc.orig	2011-05-13 01:00:56.000000000 +0200
+++ src/vw/FileIO/MemoryImageResourcePNG.cc	2012-05-06 11:29:59.000000000 +0200
@@ -11,6 +11,8 @@
 
 namespace vw {
 
+typedef void * voidp;
+
 class SrcMemoryImageResourcePNG::Data : public fileio::detail::PngIODecompress {
     boost::shared_array<const uint8> m_data;
     const uint8 * m_cur;
