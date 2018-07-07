Make sure WORDS_BIGENDIAN is available on big endian archs like
powerpc{,64}.

--- frontend/mp4read.c.orig	2018-06-26 06:56:37 UTC
+++ frontend/mp4read.c
@@ -24,6 +24,7 @@
 #include <time.h>
 #include <limits.h>
 
+#include "config.h"
 #include "unicode_support.h"
 #include "mp4read.h"
 
