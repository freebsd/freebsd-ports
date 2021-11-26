--- util.h.orig	2021-11-26 15:40:17 UTC
+++ util.h
@@ -43,7 +43,7 @@ char* itoa10(const T& value, char* result) {
 	// Only apply negative sign for base 10
 	if(std::numeric_limits<T>::is_signed) {
 		// Avoid compiler warning in cases where T is unsigned
-		if (value <= 0 && value != 0) *out++ = '-';
+		if (value <= 0) *out++ = '-';
 	}
 	reverse( result, out );
 	*out = 0; // terminator
