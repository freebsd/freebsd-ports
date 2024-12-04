--- src/common/byte_stream.cpp.orig	2024-06-14 05:59:32 UTC
+++ src/common/byte_stream.cpp
@@ -1118,7 +1118,7 @@ std::unique_ptr<ByteStream> ByteStream::OpenFile(const
     std::snprintf(temporaryFileName, fileNameLength + 8, "%s.XXXXXX", fileName);
 
     // fill in random characters
-#if defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) || defined(__FreeBSD__)
     mkstemp(temporaryFileName);
 #else
     mktemp(temporaryFileName);
