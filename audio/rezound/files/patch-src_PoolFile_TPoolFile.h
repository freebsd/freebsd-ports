--- src/PoolFile/TPoolFile.h.orig	2013-02-10 06:35:02 UTC
+++ src/PoolFile/TPoolFile.h
@@ -399,10 +399,8 @@ private:
 
 };
 
-/* this would be needed if I were utilizing gcc's implicit instantiation for TPoolFile
 #define __TPoolFile_H__CPP
 #include "TPoolFile.cpp"
 #undef __TPoolFile_H__CPP
-*/
 
 #endif
