--- io/wavout/src/wavoutpmo.cpp.orig	2003-09-16 17:35:07 UTC
+++ io/wavout/src/wavoutpmo.cpp
@@ -28,7 +28,6 @@ ________________________________________
 #endif
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 #include <string>
 
 /* project headers */
@@ -124,7 +124,7 @@ Init(OutputInfo* info)
    // it, appending an ! to the filename, and changing the extention
    // to wav
    std::string path;
-   char *pPtr = strrchr(GetUrl().c_str(), DIR_MARKER);
+   const char *pPtr = strrchr(GetUrl().c_str(), DIR_MARKER);
    if (pPtr){
       path = pPtr+1;
       pPtr = strrchr(path.c_str(), '.');
