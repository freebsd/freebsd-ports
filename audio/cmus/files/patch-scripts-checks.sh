--- scripts/checks.sh.orig	2014-08-11 07:48:28 UTC
+++ scripts/checks.sh
@@ -677,11 +677,15 @@ check_dl()
 check_iconv()
 {
 	HAVE_ICONV=n
-	if check_library ICONV "" "-liconv"
+	if check_function iconv
+	then
+		echo "libc contains iconv"
+		makefile_var ICONV_CFLAGS ""
+		makefile_var ICONV_LIBS ""
+	elif check_library ICONV "" "-liconv"
 	then
 		echo "taking iconv from libiconv"
 	else
-		echo "assuming libc contains iconv"
 		makefile_var ICONV_CFLAGS ""
 		makefile_var ICONV_LIBS ""
 	fi
