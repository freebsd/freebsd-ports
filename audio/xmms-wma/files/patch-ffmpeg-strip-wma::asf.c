--- ffmpeg-strip-wma/asf.c.orig	Sun Oct 23 08:03:33 2005
+++ ffmpeg-strip-wma/asf.c	Sun Oct 23 08:03:37 2005
@@ -16,10 +16,13 @@
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
+
+#if defined(USE_ICONV)
+#include <iconv.h>
+#endif /* USE_ICONV */
+
 #include "avformat.h"
 #include "avi.h"
-//#include "mpegaudio.h"
-#include <iconv.h>
 
 #undef NDEBUG
 #include <assert.h>
@@ -830,6 +833,7 @@
     return str;
 }
 
+#if defined(USE_ICONV)
 static void tag_recode(char *before, unsigned int len)
 {
        int result;
@@ -842,7 +846,7 @@
        unsigned int length = len;
 
        memcpy(ansb, before, len);
-       frt = iconv_open(getlocale(), "UNICODE");
+       frt = iconv_open(getlocale(), "UTF-16LE");
        if (frt == (iconv_t) - 1)
        {
            return;
@@ -859,6 +863,7 @@
 		return;
        return;
 }
+#endif /* USE_ICONV */
 
 static void get_str16_nolen(ByteIOContext *pb, int len, char *buf, int buf_size)
 {
@@ -873,7 +878,9 @@
             *q++ = c;
         len--;
     }
+#if defined(USE_ICONV)
     tag_recode(buf, lenz);
+#endif /* USE_ICONV */
 }
 
 static int asf_probe(AVProbeData *pd)
