--- cmn/utils.cpp.orig	2012-05-27 06:52:30.000000000 +0900
+++ cmn/utils.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -30,16 +30,16 @@
 
 // Include Files
 #include "stdafx.h"
-#include <iostream.h>
+#include <iostream>
 #include <limits.h>
 #include <string.h>
 #include <ctype.h>
-#include <fstream.h>
+#include <fstream>
 #if WIN32
 #include <strstrea.h>
 #endif
 #if X11
-#include <strstream.h>
+#include <sstream>
 #endif
 
 #ifdef WIN32
@@ -422,10 +422,8 @@
 
 
 char* Utils::get_OS_info() {
-  ostrstream ret;
-
-
 #ifdef WIN32
+  stringstream ret;
   OSVERSIONINFO osInfo;
   osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
   Boolean set = False;
@@ -465,12 +463,11 @@
           Utils::strcmp(osInfo.szCSDVersion," ")) {
         ret << '(' << osInfo.szCSDVersion << ')';
       }
-      ret << ends;
     }
   }
 
   if (!set) {
-    ret << "Unknown Win32" << ends;
+    ret << "Unknown Win32";
   }
 #endif
 
@@ -494,20 +491,15 @@
         if (buffer[strLen - 1] == '\n') {
           buffer[strLen - 1] = '\0';
         }
-        ret << buffer << ends;
-        set = True;
+        return strdup(buffer);
       }
     }
     pclose(fp);
   }
 
-  if (!set) {
-    ret << "Unknown UNIX" << ends;
-  }
+  return strdup("Unknown UNIX");
 #endif
 
-
-  return ret.str();
 }
 
 
@@ -605,7 +597,7 @@
   // Not tested.
   out->write_int(len);
   for (int n = 0; n < len; n++) {
-    out->write_int((int)data[n]);
+    out->write_int((long)data[n]);
   }
 }
 
@@ -761,7 +753,7 @@
 
 
 private:
-  Bucket* HashTable::_get(int &index,void* key);
+  Bucket* _get(int &index,void* key);
   /* MODIFIES: index */
   /* EFFECTS: Internal helper function.  Return the Bucket containing key
      or NULL if not found.  Set index to the bucket list for key whether
@@ -944,7 +936,7 @@
 // Pretty crappy hash function, I know.
 // Careful if bucketsNum is a power of 2.
 int HashTable::defaultHash(void* key,int bucketsNum) {
-  return ((unsigned int)key) % bucketsNum;
+  return ((unsigned long)key) % bucketsNum;
 }
 
 
@@ -1024,7 +1016,7 @@
 #endif
 
 #if X11
-  cout << str << endl;
+  std::cout << str << std::endl;
 #endif
 }
 
