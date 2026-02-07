--- ui/zenoedit/launch/viewdecode.h.orig	2024-04-23 11:14:05 UTC
+++ ui/zenoedit/launch/viewdecode.h
@@ -1,10 +1,10 @@
 #pragma once
 
-#ifdef ZENO_MULTIPROCESS
+//#ifdef ZENO_MULTIPROCESS
 #include <cstddef>
 
 void viewDecodeClear();
 void viewDecodeAppend(const char *buf, size_t n);
 void viewDecodeSetFrameCache(const char *path, int gcmax);
 void viewDecodeFinish();
-#endif
+//#endif
