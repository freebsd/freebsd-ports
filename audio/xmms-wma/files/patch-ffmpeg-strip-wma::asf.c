--- ffmpeg-strip-wma/asf.c.orig	Wed May 26 19:16:39 2004
+++ ffmpeg-strip-wma/asf.c	Mon Jun 13 08:18:01 2005
@@ -16,10 +16,13 @@
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
+
+#ifdef USE_ICONV
+#include <iconv.h>
+#endif
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
 
+#ifdef USE_ICONV
 static void tag_recode(char *before, int len)
 {
        int result;
@@ -842,7 +846,7 @@
        int length = len;
 
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
+#endif
 
 static void get_str16_nolen(ByteIOContext *pb, int len, char *buf, int buf_size)
 {
@@ -868,12 +873,17 @@
     q = buf;
     lenz = len;
     while (len > 0) {
-        c = get_byte(pb);
-        if ((q - buf) < buf_size-1)
-            *q++ = c;
-        len--;
+    	c = get_byte(pb);
+	if ((q - buf) < buf_size - 1)
+		*q++ = c;
+	len--;
     }
-    tag_recode(buf, lenz);
+
+#ifdef USE_ICONV
+	tag_recode(buf, lenz);
+#else	
+    *q = '\0';			  
+#endif
 }
 
 static int asf_probe(AVProbeData *pd)
