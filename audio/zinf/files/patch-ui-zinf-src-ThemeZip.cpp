--- ui/zinf/src/ThemeZip.cpp.orig	Sun Feb 23 09:35:06 2003
+++ ui/zinf/src/ThemeZip.cpp	Thu Aug 21 21:56:19 2003
@@ -24,6 +24,10 @@
 #include <time.h>
 #include <stdio.h>
 #include <ctype.h>
+#include <inttypes.h>
+#if HAVE_STDINT_H
+#include <stdint.h>
+#endif
 
 #ifdef WIN32
 #include <windows.h>
@@ -145,7 +149,7 @@
        oFile = *(*i);
        pPtr = strrchr(oFile.c_str(), DIR_MARKER);
        if (pPtr)
-           oFile.erase(0, ((int)pPtr - (int)oFile.c_str()) + 1);
+           oFile.erase(0, ((uintptr_t)pPtr - (uintptr_t)oFile.c_str()) + 1);
 
        pIn = fopen((*i)->c_str(), "rb");
        if (pIn == NULL)
@@ -424,7 +428,7 @@
 
        oUnpackFile = string(TarRecord.header.name);
        // in case we have sub-directory in tar, take only filename
-       unsigned int uPos;
+       uintptr_t uPos;
        uPos=oUnpackFile.rfind('/');
        if(uPos!=oUnpackFile.npos) oUnpackFile.erase(0,uPos+1);
 
@@ -553,7 +557,7 @@
         // see if it is directory record we are looking for
         if(TarRecord.header.typeflag == DIRTYPE)
         {
-            unsigned int uPos;
+            uintptr_t uPos;
             oDescriptiveName = string (TarRecord.header.name);
 
             // erase trailing slash
