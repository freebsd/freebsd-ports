--- UnAlz.cpp.orig
+++ UnAlz.cpp
@@ -37,7 +37,7 @@
 #	include <errno.h>
 #endif
 
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #	include <sys/param.h>	// __NetBSD_Version__
 #	include <errno.h>		// iconv.h 때문에 필요 
 #endif
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
 
