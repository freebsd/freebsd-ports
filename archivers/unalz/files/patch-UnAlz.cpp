--- UnAlz.cpp.orig	2018-02-26 21:09:31 UTC
+++ UnAlz.cpp
@@ -37,7 +37,7 @@
 #	include <errno.h>
 #endif
 
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #	include <sys/param.h>	// __NetBSD_Version__
 #	include <errno.h>		// iconv.h
 #endif
@@ -432,7 +432,7 @@ BOOL CUnAlz::ReadLocalFileheader()
 	FRead(zipHeader.fileName, zipHeader.head.fileNameLength);
 	if(zipHeader.head.fileNameLength > MAX_PATH - 5)
 		zipHeader.head.fileNameLength = MAX_PATH - 5;
-	zipHeader.fileName[zipHeader.head.fileNameLength] = (CHAR)NULL;
+	zipHeader.fileName[zipHeader.head.fileNameLength] = (CHAR)0;
 
 
 #ifdef _UNALZ_ICONV		// codepage convert
@@ -447,7 +447,7 @@ BOOL CUnAlz::ReadLocalFileheader()
 	size_t size;
 	char inbuf[ICONV_BUF_SIZE];
 	char outbuf[ICONV_BUF_SIZE];
-#if defined(__FreeBSD__) || defined(__CYGWIN__) ||  defined(__NetBSD__)
+#if defined(__CYGWIN__) ||  defined(__NetBSD__)
 	const char *inptr = inbuf;
 #else
 	char *inptr = inbuf;
@@ -937,7 +937,7 @@ BOOL CUnAlz::DigPath(const char* szPathN
 	{
 		if(*last=='/' || *last=='\\') 
 		{
-			*last = (char)NULL;
+			*last = (char)0;
 			break;
 		}
 		last --;
@@ -1870,7 +1870,11 @@ void CUnAlz::DecryptingData(int nSize, B
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
 
