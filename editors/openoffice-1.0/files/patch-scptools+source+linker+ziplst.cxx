--- scptools/source/linker/ziplst.cxx.orig	Sun Jul 21 00:32:40 2002
+++ scptools/source/linker/ziplst.cxx	Sun Jul 21 00:32:43 2002
@@ -278,6 +278,7 @@
 #define OS_SOLI			"solia"
 #define OS_WINDOWS		"windows"
 #define OS_LINUX		"linux"
+#define OS_FREEBSD		"freebsd"
 #define OS_OS2			"os2"
 
 ByteString _OS2Alpha( const ByteString& rStr )
@@ -290,6 +291,8 @@
 		return OS_SOLI;
 	else if( rStr.CompareIgnoreCaseToAscii("unxlngi",7) == COMPARE_EQUAL )
 		return OS_LINUX;
+	else if( rStr.CompareIgnoreCaseToAscii("unxfbsdi",7) == COMPARE_EQUAL )
+		return OS_FREEBSD;
 	else if( rStr.CompareIgnoreCaseToAscii("os2icci",7) == COMPARE_EQUAL )
 		return OS_OS2;
 
