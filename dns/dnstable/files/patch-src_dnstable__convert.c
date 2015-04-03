--- src/dnstable_convert.c.orig	2014-05-21 21:37:25 UTC
+++ src/dnstable_convert.c
@@ -24,6 +24,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/endian.h>
 
 #include <dnstable.h>
 #include <mtbl.h>
