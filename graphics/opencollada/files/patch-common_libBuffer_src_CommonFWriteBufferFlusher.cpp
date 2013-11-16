--- common/libBuffer/src/CommonFWriteBufferFlusher.cpp.orig	2013-11-06 03:41:32.000000000 +0100
+++ common/libBuffer/src/CommonFWriteBufferFlusher.cpp	2013-11-16 10:49:45.000000000 +0100
@@ -89,7 +89,7 @@
 		FilePosType currentPos = ftello64(mStream);
 #elif defined( _WIN32)
 		FilePosType currentPos = _ftelli64(mStream);
-#elif defined (__APPLE__)
+#elif defined (__APPLE__) || defined(__FreeBSD__)
 		FilePosType currentPos = ftello(mStream);
 #else
 		FilePosType currentPos = ftello64(mStream);
@@ -114,7 +114,7 @@
   			return (fseeko64(mStream,0,SEEK_END) == 0);
 #elif defined( _WIN32)
 			return (_fseeki64(mStream, 0, SEEK_END) == 0);
-#elif defined (__APPLE__)
+#elif defined (__APPLE__) || defined(__FreeBSD__)
 			return (fseeko(mStream, 0, SEEK_END) == 0);
 #else
 			return (fseeko64(mStream, 0, SEEK_END) == 0);
@@ -134,7 +134,7 @@
   				bool success = (fseeko64(mStream,pos,SEEK_SET) == 0);
 #elif defined( _WIN32)
 				bool success = (_fseeki64(mStream, pos, SEEK_SET) == 0);
-#elif defined (__APPLE__)
+#elif defined (__APPLE__) || defined(__FreeBSD__)
 				bool success = (fseeko(mStream, pos, SEEK_SET) == 0);
 #else
 				bool success = (fseeko64(mStream, pos, SEEK_SET) == 0);
