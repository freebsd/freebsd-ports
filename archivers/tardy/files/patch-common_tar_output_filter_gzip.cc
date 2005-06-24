--- common/tar/output/filter/gzip.cc.orig	Fri Jun 24 09:17:36 2005
+++ common/tar/output/filter/gzip.cc	Fri Jun 24 09:17:57 2005
@@ -26,6 +26,7 @@
 #include <ac/stdlib.h>
 #include <ac/string.h>
 #include <tar/output/filter/gzip.h>
+#include <unistd.h>
 
 #ifndef Z_BUFSIZE
 #ifdef MAXSEG_64K
