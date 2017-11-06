--- src/modules/rijndael/libkvirijndael.cpp.orig	2011-07-23 15:15:56 UTC
+++ src/modules/rijndael/libkvirijndael.cpp
@@ -328,7 +328,7 @@
 			setLastError(__tr2qs("The message is not a hexadecimal string: this is not my stuff"));
 			return false;
 		} else {
-			if(len > 0)
+			if(*len > 0)
 			{
 				*outBuffer = (char *)KviMemory::allocate(*len);
 				KviMemory::move(*outBuffer,tmpBuf,*len);
@@ -354,7 +354,7 @@
 			setLastError(__tr2qs("The message is not a base64 string: this is not my stuff"));
 			return false;
 		} else {
-			if(len > 0)
+			if(*len > 0)
 			{
 				*outBuffer = (char *)KviMemory::allocate(*len);
 				KviMemory::move(*outBuffer,tmpBuf,*len);
