--- FeLib/Source/festring.cpp.orig	2004-11-11 20:27:44.000000000 +0300
+++ FeLib/Source/festring.cpp	2013-11-08 16:54:46.925772448 +0400
@@ -11,6 +11,7 @@
  */
 
 #include <cctype>
+#include <cstdlib>
 
 #include "festring.h"
 #include "allocate.h"
@@ -116,7 +117,7 @@
 {
   Size = N;
   Reserved = N|FESTRING_PAGE;
-  char* Ptr = 4 + new char[Reserved + 5];
+  char* Ptr = sizeof(ulong) + new char[Reserved + 5];
   REFS(Ptr) = 0;
   Data = Ptr;
   memcpy(Ptr, CStr, N);
@@ -137,7 +138,7 @@
       DeletePtr = &REFS(OldPtr);
 
     Reserved = NewSize|FESTRING_PAGE;
-    char* NewPtr = 4 + new char[Reserved + 5];
+    char* NewPtr = sizeof(ulong) + new char[Reserved + 5];
     REFS(NewPtr) = 0;
     Data = NewPtr;
     memcpy(NewPtr, OldPtr, OldSize);
@@ -150,7 +151,7 @@
   {
     Size = 1;
     Reserved = FESTRING_PAGE;
-    char* Ptr = 4 + new char[FESTRING_PAGE + 5];
+    char* Ptr = sizeof(ulong) + new char[FESTRING_PAGE + 5];
     REFS(Ptr) = 0;
     Ptr[0] = Char;
     Data = Ptr;
@@ -174,7 +175,7 @@
       DeletePtr = &REFS(OldPtr);
 
     Reserved = NewSize|FESTRING_PAGE;
-    char* NewPtr = 4 + new char[Reserved + 5];
+    char* NewPtr = sizeof(ulong) + new char[Reserved + 5];
     REFS(NewPtr) = 0;
     Data = NewPtr;
     memcpy(NewPtr, OldPtr, OldSize);
@@ -205,7 +206,7 @@
   }
 
   Reserved = N|FESTRING_PAGE;
-  Ptr = 4 + new char[Reserved + 5];
+  Ptr = sizeof(ulong) + new char[Reserved + 5];
   REFS(Ptr) = 0;
   Data = Ptr;
   memset(Ptr, C, N);
@@ -240,7 +241,7 @@
     }
 
     Reserved = N|FESTRING_PAGE;
-    NewPtr = 4 + new char[Reserved + 5];
+    NewPtr = sizeof(ulong) + new char[Reserved + 5];
     REFS(NewPtr) = 0;
     Data = NewPtr;
     memcpy(NewPtr, OldPtr, OldSize);
@@ -259,7 +260,7 @@
 	--REFS(OldPtr);
 
     Reserved = N|FESTRING_PAGE;
-    NewPtr = 4 + new char[Reserved + 5];
+    NewPtr = sizeof(ulong) + new char[Reserved + 5];
     REFS(NewPtr) = 0;
     Data = NewPtr;
     memcpy(NewPtr, OldPtr, N);
@@ -362,7 +363,7 @@
       sizetype NewSize = MoveReq ? OldSize - Length : Pos;
       Size = NewSize;
       Reserved = NewSize|FESTRING_PAGE;
-      char* Ptr = 4 + new char[Reserved + 5];
+      char* Ptr = sizeof(ulong) + new char[Reserved + 5];
       REFS(Ptr) = 0;
       Data = Ptr;
       OwnsData = true;
@@ -411,7 +412,7 @@
       }
 
       Reserved = NewSize|FESTRING_PAGE;
-      char* NewPtr = 4 + new char[Reserved + 5];
+      char* NewPtr = sizeof(ulong) + new char[Reserved + 5];
       REFS(NewPtr) = 0;
       Data = NewPtr;
       memcpy(NewPtr, OldPtr, Pos);
