#
# If the network card's buffer is full, send returns -1 and sets
# errno to ENOBUFS, which causes issues with the UDP bandwidth tests.
# Check if errno != ENOBUFS after write(2).
#
--- src/Client.cpp.orig	2010-04-01 20:23:17 UTC
+++ src/Client.cpp
@@ -157,7 +157,7 @@ void Client::RunTCP( void ) {
 
         // perform write 
         currLen = write( mSettings->mSock, mBuf, mSettings->mBufLen ); 
-        if ( currLen < 0 ) {
+        if ( currLen < 0 && errno != ENOBUFS ) {
             WARN_errno( currLen < 0, "write2" ); 
             break; 
         }
