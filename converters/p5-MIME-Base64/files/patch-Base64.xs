--- Base64.xs.orig	Thu Jan  8 09:07:26 2004
+++ Base64.xs	Mon Jan 12 13:46:56 2004
@@ -399,7 +399,7 @@
 		    whitespace = 0;
                 }
             	if (*str == '=') {
-		    if ((str + 2) < end && isXDIGIT(str[1]) && isXDIGIT(str[2])) {
+		    if ((str + 2) < end && isxdigit(str[1]) && isxdigit(str[2])) {
 	                char buf[3];
                         str++;
 	                buf[0] = *str++;
