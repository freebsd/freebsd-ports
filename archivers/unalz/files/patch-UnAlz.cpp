--- UnAlz.cpp.orig
+++ UnAlz.cpp
@@ -1907,7 +1907,11 @@
 ////////////////////////////////////////////////////////////////////////////////////////////////////
 UINT32 CUnAlz::CRC32(UINT32 l, BYTE c)
 {
+#ifndef Z_U4
 	const unsigned long *CRC_TABLE = get_crc_table();
+#else
+	const Z_U4 *CRC_TABLE = get_crc_table();
+#endif
 	return CRC_TABLE[(l ^ c) & 0xff] ^ (l >> 8);
 }
 
