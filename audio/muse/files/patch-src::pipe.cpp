--- src/pipe.cpp.orig	Mon Dec  8 17:20:33 2003
+++ src/pipe.cpp	Fri Jun  3 16:58:02 2005
@@ -25,7 +25,8 @@
 */
 
 #include <iostream>
-#include <stdlib.h>
+#include <cstdlib>
+#include <cerrno>
 #include <audioproc.h>
 #include <pipe.h>
 #include <jutils.h>
@@ -118,9 +119,9 @@
     }
     /* --- */
 
-    (char*)start += currentBlockSize;
+    start = (char*)start + currentBlockSize;
     len -= currentBlockSize;
-    (char*)pp += currentBlockSize;
+    pp = (float*)pp + currentBlockSize;
     length -= currentBlockSize;
     if ((end!=buffer) && (start==bufferEnd))
       start = buffer;
@@ -146,8 +147,8 @@
     }
     /* --- */
     
-    (char*)pp += len;
-    (char*)start += len;
+    pp = (float*)pp + len;
+    start = (char*)start + len;
     length -= len;
     if ((end!=buffer) && (start==bufferEnd))
       start = buffer;
@@ -224,9 +225,9 @@
     }
     /* --- */
 
-    (char*)start += currentBlockSize;
+    start = (char*)start + currentBlockSize;
     len -= currentBlockSize;
-    (char*)pp += currentBlockSize;
+    pp = (float**)pp + currentBlockSize;
     length -= currentBlockSize;
     if ((end!=buffer) && (start==bufferEnd))
       start = buffer;
@@ -253,8 +254,8 @@
       }
       /* --- */
       
-      (char*)pp += len;
-      (char*)start += len;
+      pp = (float**)pp + len;
+      start = (char*)start + len;
       length -= len;
       if ((end!=buffer) && (start==bufferEnd))
 	start = buffer;
@@ -309,9 +310,9 @@
       pp[c] += (int32_t) ((IN_DATATYPE*)start)[c];
     /* --- */
 
-    (char*)start += currentBlockSize;
+    start = (char*)start + currentBlockSize;
     len -= currentBlockSize;
-    (char*)pp += currentBlockSize;
+    pp = (int32_t*)pp + currentBlockSize;
     length -= currentBlockSize;
     if ((end!=buffer) && (start==bufferEnd))
       start = buffer;
@@ -324,8 +325,8 @@
 	pp[c] += (int) ((IN_DATATYPE*)start)[c];
       /* --- */
 
-      (char*)pp += len;
-      (char*)start += len;
+      pp = (int32_t*)pp + len;
+      start = (char*)start + len;
       length -= len;
       if ((end!=buffer) && (start==bufferEnd))
 	start = buffer;
@@ -372,17 +373,17 @@
     /* fill */
     memcpy(data, start, currentBlockSize);
     
-    (char*)start += currentBlockSize;
+    start = (char*)start + currentBlockSize;
     len -= currentBlockSize;
-    (char*)data += currentBlockSize;
+    data = (char*)data + currentBlockSize;
     length -= currentBlockSize;
     if ((end!=buffer) && (start==bufferEnd))
       start = buffer;
     
     if (len) { /* short circuit */
       memcpy(data, start, len);
-      (char*)data += len;
-      (char*)start += len;
+      data = (char*)data + len;
+      start = (char*)start + len;
       length -= len;
       if ((end!=buffer) && (start==bufferEnd))
 	start = buffer;
@@ -418,19 +419,19 @@
     currentBlockSize=MIN(currentBlockSize, len);
     ::memcpy(end, data, currentBlockSize);
     
-    (char*)end += currentBlockSize;
+    end = (char*)end + currentBlockSize;
     
     len -= currentBlockSize;
     
-    (char*)data += currentBlockSize;
+    data = (char*)data + currentBlockSize;
     length -= currentBlockSize;
     if ((start!=buffer) && (end==bufferEnd))
       end = buffer;
 		
     if (len) { // short circuit		
       ::memcpy(end, data, len);
-      (char*)data += len;
-      (char*)end += len;
+      data = (char*)data + len;
+      end = (char*)end + len;
       length -= len;
       
       if ((start!=buffer) && (end==bufferEnd))
