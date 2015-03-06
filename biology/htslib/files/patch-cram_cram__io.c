--- cram/cram_io.c.orig	2015-02-03 16:22:23 UTC
+++ cram/cram_io.c
@@ -53,6 +53,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #include <assert.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <zlib.h>
 #ifdef HAVE_LIBBZ2
 #include <bzlib.h>
