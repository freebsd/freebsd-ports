--- src/scan-mp3.c.orig	2007-09-25 16:55:23.000000000 +0900
+++ src/scan-mp3.c	2011-09-05 13:52:16.000000000 +0900
@@ -18,6 +18,15 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */

+#define USE_CP932
+
+#ifdef USE_CP932
+    #define UNKNOWN_STR    "UNKNOWN"
+    #ifndef FILESYSTEM_CES
+        #define FILESYSTEM_CES "CP932"
+    #endif
+#endif
+
 #ifdef HAVE_CONFIG_H
 #  include "config.h"
 #endif
@@ -34,6 +43,10 @@
 #include <string.h>
 #include <time.h>

+#ifdef USE_CP932
+    #include <iconv.h>
+#endif
+
 #include "daapd.h"
 #include "conf.h"
 #include "err.h"
@@ -289,6 +302,96 @@
     return 1;
 }

+#ifdef USE_CP932
+#define MAX_ICONV_BUF 1024
+
+typedef enum {
+    ICONV_OK,
+    ICONV_TRYNEXT,
+    ICONV_FATAL
+}   iconv_result;
+
+static iconv_result do_convert(const char* to_ces, const char* from_ces,
+                   char *inbuf,  size_t inbytesleft,
+                   char *outbuf_orig, size_t outbytesleft_orig) {
+    size_t rc;
+    iconv_result ret = ICONV_OK;
+
+    size_t outbytesleft = outbytesleft_orig - 1;
+    char* outbuf = outbuf_orig;
+
+    iconv_t cd  = iconv_open(to_ces, from_ces);
+    if (cd == (iconv_t)-1) {
+        return ICONV_FATAL;
+    }
+    rc = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
+    if (rc == (size_t)-1) {
+        if (errno == E2BIG) {
+            ret = ICONV_FATAL;
+        } else {
+            ret = ICONV_TRYNEXT;
+            memset(outbuf_orig, '\0', outbytesleft_orig);
+        }
+    }
+    iconv_close(cd);
+
+    return ret;
+}
+
+static unsigned char* get_utf8_text(const id3_ucs4_t* native_text) {
+    unsigned char* utf8_text = NULL;
+    char * in, * in8, * iconv_buf;
+    iconv_result rc;
+
+    in = (char*)id3_ucs4_latin1duplicate(native_text);
+    if (!in) goto out;
+
+    in8 = (char*)id3_ucs4_utf8duplicate(native_text);
+    if (!in8) {
+      free(in);
+      goto out;
+    }
+
+    iconv_buf = (char*)calloc(MAX_ICONV_BUF, sizeof(char));
+    if (!iconv_buf) {
+      free(in); free(in8);
+      goto out;
+    }
+
+    /* (1) try utf8 -> cp932 */
+    rc = do_convert("CP932", "UTF-8", in8, strlen(in8), iconv_buf, MAX_ICONV_BUF);
+    if (rc == ICONV_OK) {
+        utf8_text = (unsigned char*)in8;
+        free(iconv_buf);
+    } else if (rc == ICONV_TRYNEXT) {
+        /* (2) try cp932 -> utf8 */
+        rc = do_convert("UTF-8", "CP932", in, strlen(in), iconv_buf, MAX_ICONV_BUF);
+        if (rc == ICONV_OK) {
+            utf8_text = (unsigned char*)iconv_buf;
+        } else if (rc == ICONV_TRYNEXT) {
+            /* (3) try euc-jp -> utf8 */
+            rc = do_convert("UTF-8", "EUC-JP", in, strlen(in), iconv_buf, MAX_ICONV_BUF);
+            if (rc == ICONV_OK) {
+                utf8_text = (unsigned char*)iconv_buf;
+            } else if (rc == ICONV_TRYNEXT) {
+                /* utf-8 including non-japanese char? fallback. */
+                utf8_text = (unsigned char*)id3_ucs4_utf8duplicate(native_text);
+                free(iconv_buf);
+            }
+        }
+        free(in8);
+    }
+    free(in);
+
+  out:
+    if (!utf8_text) {
+        utf8_text = (unsigned char*)strdup(UNKNOWN_STR);
+    }
+
+    return utf8_text;
+}
+#endif
+
 int scan_mp3_get_mp3tags(char *file, MP3FILE *pmp3) {
     struct id3_file *pid3file;
     struct id3_tag *pid3tag;
@@ -352,8 +455,11 @@
             if(native_text) {
                 have_utf8=1;

-
+#ifdef USE_CP932
+		utf8_text = (char *)get_utf8_text(native_text);
+#else
                 utf8_text = (char*)id3_ucs4_utf8duplicate(native_text);
+#endif
                 if(utf8_text)
                     mem_register(utf8_text,0);
