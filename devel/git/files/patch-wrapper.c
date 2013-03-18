--- wrapper.c.orig	2013-03-13 15:15:22.000000000 -0400
+++ wrapper.c	2013-03-17 20:55:29.000000000 -0400
@@ -1,6 +1,7 @@
 /*
  * Various trivial helper wrappers around standard functions
  */
+#include <sys/param.h>
 #include "cache.h"
 
 static void do_nothing(size_t size)
@@ -139,7 +140,7 @@
 {
 	ssize_t nr;
 	while (1) {
-		nr = read(fd, buf, len);
+		nr = read(fd, buf, MIN(INT_MAX, len));
 		if ((nr < 0) && (errno == EAGAIN || errno == EINTR))
 			continue;
 		return nr;
@@ -155,7 +156,7 @@
 {
 	ssize_t nr;
 	while (1) {
-		nr = write(fd, buf, len);
+		nr = write(fd, buf, MIN(INT_MAX, len));
 		if ((nr < 0) && (errno == EAGAIN || errno == EINTR))
 			continue;
 		return nr;
