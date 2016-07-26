--- SmartPtr.h.orig	1998-11-30 19:10:00 UTC
+++ SmartPtr.h
@@ -207,16 +207,16 @@ class smartPtr : public smartPtrBase<T>
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
