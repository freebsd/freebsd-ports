--- src/SmartPtr.h.orig	Wed Oct  6 14:50:12 2004
+++ src/SmartPtr.h	Wed Oct  6 14:51:29 2004
@@ -207,16 +207,16 @@
     {
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
-            pBufCurrent = bufBegin = bufEnd = 0;
-            bufLen = 0;
-            status = false;
+            this->pBufCurrent = this->bufBegin = this->bufEnd = 0;
+            this->bufLen = 0;
+            this->status = false;
         }
     }
 };
