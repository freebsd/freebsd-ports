--- ./src/libmtp.c.orig	2008-08-17 01:01:13.000000000 +0400
+++ ./src/libmtp.c	2009-01-14 01:12:55.000000000 +0300
@@ -44,6 +44,7 @@
 #include "device-flags.h"
 #include "playlist-spl.h"
 
+#include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
