XMP code is not dealing with format types properly.
Provide a variable that matches the format string to
avoid crashes when sizeof(long long) != sizeof(XMP_Int64).

filed as https://github.com/Exiv2/exiv2/pull/2671

--- xmpsdk/src/XMPUtils.cpp.orig	2023-05-08 16:01:13 UTC
+++ xmpsdk/src/XMPUtils.cpp
@@ -1215,7 +1215,7 @@ XMPUtils::ConvertToInt64 ( XMP_StringPtr strValue )
 
 	int count;
 	char nextCh;
-	XMP_Int64 result;
+	long long result;
 
 	if ( ! XMP_LitNMatch ( strValue, "0x", 2 ) ) {
 		count = sscanf ( strValue, "%lld%c", &result, &nextCh );
