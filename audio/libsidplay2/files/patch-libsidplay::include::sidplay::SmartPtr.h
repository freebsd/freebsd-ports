--- libsidplay/include/sidplay/SmartPtr.h.orig	Tue Jun 15 05:08:04 2004
+++ libsidplay/include/sidplay/SmartPtr.h	Wed Aug 18 00:47:50 2004
@@ -211,16 +211,16 @@
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
