--- ./src/disc_freebsd.c.orig	2011-03-27 08:20:45.000000000 -0400
+++ ./src/disc_freebsd.c	2011-03-27 08:21:02.000000000 -0400
@@ -33,6 +33,7 @@
 #include <sys/cdio.h>
 #include <unistd.h>
 #include <assert.h>
+#include <netinet/in.h>
 
 
 #include "discid/discid_private.h"
