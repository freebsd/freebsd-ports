--- src/dnstable_lookup.c.orig	2014-04-02 00:26:43 UTC
+++ src/dnstable_lookup.c
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/endian.h>
 
 #include <dnstable.h>
 #include <mtbl.h>
