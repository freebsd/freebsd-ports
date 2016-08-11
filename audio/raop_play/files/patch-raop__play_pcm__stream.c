--- raop_play/pcm_stream.c.orig	2005-12-16 14:17:01 UTC
+++ raop_play/pcm_stream.c
@@ -19,7 +19,7 @@
  *****************************************************************************/
 #include <unistd.h>
 #include <fcntl.h>
-#include <asm/types.h>
+#include <sys/types.h>
 #include <stdio.h>
 #include <sys/poll.h>
 #define PCM_STREAM_C_
