--- shout/shout_private.h.orig	Fri Nov 29 20:51:56 2002
+++ shout/shout_private.h	Wed May 14 14:26:24 2003
@@ -14,14 +14,6 @@
 #  include <inttypes.h>
 #endif
 
-#  if SIZEOF_INT == 8
-typedef unsigned int uint64_t;
-#  elif SIZEOF_LONG == 8
-typedef unsigned long uint64_t;
-#  elif SIZEOF_LONG_LONG == 8
-typedef unsigned long long uint64_t;
-#  endif
-
 #define LIBSHOUT_DEFAULT_HOST "localhost"
 #define LIBSHOUT_DEFAULT_PORT 8000
 #define LIBSHOUT_DEFAULT_FORMAT SHOUT_FORMAT_VORBIS
