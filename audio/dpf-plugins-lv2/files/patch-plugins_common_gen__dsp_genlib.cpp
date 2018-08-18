--- plugins/common/gen_dsp/genlib.cpp.orig	2018-04-27 06:05:19 UTC
+++ plugins/common/gen_dsp/genlib.cpp
@@ -29,7 +29,8 @@ OR THE USE OR OTHER DEALINGS IN THE SOFT
 #if DISTRHO_OS_MAC
 # include <malloc/malloc.h>
 #else
-# include <malloc.h>
+# include <stdlib.h>
+#include <malloc_np.h>
 # if DISTRHO_OS_WINDOWS
 #  define malloc_size _msize
 # else
