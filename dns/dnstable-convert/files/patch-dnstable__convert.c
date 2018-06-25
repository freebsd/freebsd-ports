--- dnstable_convert.c.orig	2018-06-05 14:55:58 UTC
+++ dnstable_convert.c
@@ -24,6 +24,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/endian.h>
 
 #include <dnstable.h>
 #include <mtbl.h>
