--- lib/converter.c.orig	Sun Nov 26 22:10:22 2000
+++ lib/converter.c	Mon Mar 18 19:49:56 2002
@@ -92,14 +92,14 @@
 		if (ch == UCS_CHAR_NONE) {
 			/* Incomplete character in input buffer */
 			errno = EINVAL;
-			return res;
+			return (size_t)(-1);
 		}
 		if (ch == UCS_CHAR_INVALID) {
 			/* Invalid character in source buffer */
 			*inbytesleft += *inbuf - ptr;
 			*inbuf = ptr;
 			errno = EILSEQ;
-			return res;
+			return (size_t)(-1);
 		}
 		size = ICONV_CES_CONVERT_FROM_UCS(&(uc->to), ch,
 		                                  outbuf, outbytesleft);
@@ -116,7 +116,7 @@
 			*inbytesleft += *inbuf - ptr;
 			*inbuf = ptr; 
 			errno = E2BIG;
-			return res;
+			return (size_t)(-1);
 		}
 	}
 	return res;
@@ -156,14 +156,24 @@
 {
 	if (inbuf && *inbuf && inbytesleft && *inbytesleft > 0 && outbuf
 			&& *outbuf && outbytesleft && *outbytesleft > 0) {
-		size_t len = *inbytesleft < *outbytesleft ? *inbytesleft
-							  : *outbytesleft;
+		size_t result, len;
+		if (*inbytesleft < *outbytesleft) {
+			result = 0;
+			len = *inbytesleft;
+		} else {
+			result = (size_t)(-1);
+			errno = E2BIG;
+			len = *outbytesleft;
+		}
 		bcopy(*inbuf, *outbuf, len);
 		*inbuf += len;
 		*inbytesleft -= len;
 		*outbuf += len;
 		*outbytesleft -= len;
+
+		return result;
 	}
+
 	return 0;
 }
 
