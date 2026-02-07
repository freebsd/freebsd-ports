--- src/cpp/_nix_based/jssc.cpp.orig	2016-10-24 19:48:41 UTC
+++ src/cpp/_nix_based/jssc.cpp
@@ -545,7 +545,7 @@ JNIEXPORT jbyteArray JNICALL Java_jssc_S
     FD_CLR(portHandle, &read_fd_set);
     jbyteArray returnArray = env->NewByteArray(byteCount);
     env->SetByteArrayRegion(returnArray, 0, byteCount, lpBuffer);
-    delete lpBuffer;
+    delete[] lpBuffer;
     return returnArray;
 }
 
