--- vshadowtools/vshadowmount.c.orig	2012-05-12 00:35:33.000000000 +0900
+++ vshadowtools/vshadowmount.c	2012-05-12 00:39:10.000000000 +0900
@@ -624,7 +624,7 @@
 				 "%s: unsupported to retrieve volume size.",
 				 function );
 
-				result = -EBADFD;
+				result = -EBADF;
 
 				goto on_error;
 			}
