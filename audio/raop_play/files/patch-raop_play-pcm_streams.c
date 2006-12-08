--- raop_play/pcm_stream.c~	Fri Dec 16 23:17:01 2005
+++ raop_play/pcm_stream.c	Wed Jul  5 16:02:29 2006
@@ -19,7 +19,7 @@
  *****************************************************************************/
 #include <unistd.h>
 #include <fcntl.h>
-#include <asm/types.h>
+#include <sys/types.h>
 #include <stdio.h>
 #include <sys/poll.h>
 #define PCM_STREAM_C_
