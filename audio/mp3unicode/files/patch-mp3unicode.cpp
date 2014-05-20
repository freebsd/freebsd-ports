--- ./mp3unicode.cpp.orig	2012-05-07 12:03:19.000000000 +0000
+++ ./mp3unicode.cpp	2014-05-13 20:16:40.053475428 +0000
@@ -229,7 +229,7 @@
 			if (
 				iconv (
 					cd,
-					(char **)&from,
+					&from,
 					&from_size,
 					&to,
 					&to_size
