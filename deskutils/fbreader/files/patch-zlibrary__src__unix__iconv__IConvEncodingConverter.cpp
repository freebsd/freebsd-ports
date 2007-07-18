--- ./zlibrary/core/src/unix/iconv/IConvEncodingConverter.cpp.orig	Tue Apr 17 22:53:30 2007
+++ ./zlibrary/core/src/unix/iconv/IConvEncodingConverter.cpp	Sat Apr 21 18:50:56 2007
@@ -87,7 +87,7 @@
 	char *out = (char*)dst.data() + oldLength;
 
 iconvlabel:
-	iconv(myIConverter, &in, &inSize, &out, &outSize);
+	iconv(myIConverter, (const char**)&in, &inSize, &out, &outSize);
 	if (inSize != 0) {
 		if (myBuffer.empty()) {
 			myBuffer.append(in, inSize);
@@ -126,7 +126,7 @@
 		inSize = 1;
 		outSize = 3;
 		inBuffer[0] = i;
-		iconv(myIConverter, &in, &inSize, &out, &outSize);
+		iconv(myIConverter, (const char**)&in, &inSize, &out, &outSize);
 		if (inSize == 0) {
 			ZLUnicodeUtil::Ucs2Char ch;
 			ZLUnicodeUtil::firstChar(ch, outBuffer);
