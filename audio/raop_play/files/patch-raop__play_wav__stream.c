--- raop_play/wav_stream.c.orig	2005-12-16 14:17:01 UTC
+++ raop_play/wav_stream.c
@@ -17,7 +17,7 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
  *****************************************************************************/
-#include <asm/types.h>
+#include <sys/types.h>
 #include <stdio.h>
 #define WAV_STREAM_C
 #include "audio_stream.h"
