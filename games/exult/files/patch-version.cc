--- version.cc.orig	2022-09-03 11:51:13 UTC
+++ version.cc
@@ -210,6 +210,8 @@ void getVersionInfo(std::ostream &out) {
 
 		out << " Version " << info.dwMajorVersion << "." << info.dwMinorVersion << " Build " << LOWORD(info.dwBuildNumber & 0xFFFF);
 	}
+#elif (defined(FREEBSD))
+	out << "FreeBSD";
 #elif (defined(MACOSX))
 	out << "Mac OS X";
 #elif (defined(__IPHONEOS__))
