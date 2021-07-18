--- src/smart.h.orig	2004-07-17 21:43:15 UTC
+++ src/smart.h
@@ -17,16 +17,16 @@ class smartPtrBase
         doFree = bufOwner;
         if ( bufferLen >= 1 )
         {
-            pBufCurrent = ( bufBegin = buffer );
-            bufEnd = bufBegin + bufferLen;
-            bufLen = bufferLen;
-            status = true;
+            this->pBufCurrent = ( this->bufBegin = buffer );
+            this->bufEnd = this->bufBegin + bufferLen;
+            this->bufLen = bufferLen;
+            this->status = true;
         }
         else
         {
-            pBufCurrent = ( bufBegin = ( bufEnd = 0 ));
-            bufLen = 0;
-            status = false;
+            this->pBufCurrent = ( this->bufBegin = ( this->bufEnd = 0 ));
+            this->bufLen = 0;
+            this->status = false;
         }
     }
     
