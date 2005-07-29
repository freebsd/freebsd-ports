--- setup2/source/service/interface.cxx.orig	Sat Jul 20 23:29:33 2002
+++ setup2/source/service/interface.cxx	Sat Jul 20 23:30:02 2002
@@ -126,6 +126,8 @@
 		aExtension = "UNIX_SOLIG";
 	else if( eType == OSType_UNIX_LINUX )
 		aExtension = "UNIX_LINUX";
+	else if( eType == OSType_UNIX_LINUX )
+		aExtension = "UNIX_FREEBSD";
 	else if( eType == OSType_UNIX_HP )
 		aExtension = "UNIX_HP";
 	else if( eType == OSType_UNIX_SCO )
@@ -238,6 +240,7 @@
 	readOSConfiguration( OSType_UNIX_SOLSG );
 	readOSConfiguration( OSType_UNIX_SOLIG );
 	readOSConfiguration( OSType_UNIX_LINUX );
+	readOSConfiguration( OSType_UNIX_FREEBSD );
 	readOSConfiguration( OSType_UNIX_HP );
 	readOSConfiguration( OSType_UNIX_SCO );
 	fprintf( stdout, "\n" );
@@ -577,6 +580,7 @@
 			case OSType_UNIX_SOLSG:
 			case OSType_UNIX_SOLIG:
 			case OSType_UNIX_LINUX:
+			case OSType_UNIX_FREEBSD:
 			case OSType_UNIX_HP:
 			case OSType_UNIX_SCO:
 				return ByteString(UNX_README_FILE_NAME);
@@ -599,6 +603,7 @@
 			case OSType_UNIX_SOLSG:
 			case OSType_UNIX_SOLIG:
 			case OSType_UNIX_LINUX:
+			case OSType_UNIX_FREEBSD:
 			case OSType_UNIX_HP:
 			case OSType_UNIX_SCO:
 				return ByteString(UNX_LICENSE_FILE_NAME);
