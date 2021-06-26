--- src/commons/DBReader.cpp.orig	2021-06-25 22:40:36 UTC
+++ src/commons/DBReader.cpp
@@ -1004,7 +1004,7 @@ void DBReader<T>::setSequentialAdvice() {
 #ifdef HAVE_POSIX_MADVISE
     for(size_t i = 0; i < dataFileCnt; i++){
         size_t dataSize = dataSizeOffset[i+1] - dataSizeOffset[i];
-        if (posix_madvise (dataFiles[i], dataSize, POSIX_MADV_SEQUENTIAL) != 0){
+        if (dataSize > 0 && posix_madvise (dataFiles[i], dataSize, POSIX_MADV_SEQUENTIAL) != 0){
             Debug(Debug::ERROR) << "posix_madvise returned an error " << dataFileName << "\n";
         }
     }
