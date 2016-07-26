--- libsidplay/include/sidplay/SmartPtr.h.orig	2004-06-14 20:08:04 UTC
+++ libsidplay/include/sidplay/SmartPtr.h
@@ -211,16 +211,16 @@ class SmartPtr_sidtt : public SmartPtrBa
 	{
 		if ( bufferLen >= 1 )
 		{
-			pBufCurrent = ( bufBegin = buffer );
-			bufEnd = bufBegin + bufferLen;
-			bufLen = bufferLen;
-			status = true;
+			this->pBufCurrent = ( this->bufBegin = buffer );
+			this->bufEnd = this->bufBegin + bufferLen;
+			this->bufLen = bufferLen;
+			this->status = true;
 		}
 		else
 		{
-			pBufCurrent = bufBegin = bufEnd = 0;
-			bufLen = 0;
-			status = false;
+			this->pBufCurrent = this->bufBegin = this->bufEnd = 0;
+			this->bufLen = 0;
+			this->status = false;
 		}
 	}
 };
