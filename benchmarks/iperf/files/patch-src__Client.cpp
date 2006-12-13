#
# If the network card's buffer is full, send returns -1 and sets
# errno to ENOBUFS, which causes issues with the UDP bandwidth tests.
# Check if errno != ENOBUFS after write(2).
#
--- src/Client.cpp.orig	Wed Dec 13 11:22:18 2006
+++ src/Client.cpp	Wed Dec 13 11:22:47 2006
@@ -215,7 +215,7 @@
 
         // perform write 
         currLen = write( mSettings->mSock, mBuf, mSettings->mBufLen ); 
-        if ( currLen < 0 ) {
+        if ( currLen < 0 && errno != ENOBUFS ) {
             WARN_errno( currLen < 0, "write2" ); 
             break; 
         }
