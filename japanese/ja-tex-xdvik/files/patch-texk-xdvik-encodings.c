--- texk/xdvik/encodings.c.orig	2013-03-31 05:28:20 UTC
+++ texk/xdvik/encodings.c
@@ -69,10 +69,18 @@ OTHER DEALINGS IN THE SOFTWARE.
 #if HAVE_ICONV_H
 # include <iconv.h>
 static iconv_t m_iconv_gb_ucs4 = (iconv_t)(-1);
+static iconv_t m_iconv_jis_ucs4 = (iconv_t)(-1);
 #endif /* HAVE_ICONV_H */
 
 #include <ctype.h>
 
+#ifdef PTEX
+#include "ptexmap.h"
+#if HAVE_PTEXENC
+#include <ptexenc/unicode-jp.h>
+#include <ptexenc/ptexenc.h>
+#endif
+#endif
 #include "util.h"
 #include "encodings.h"
 #include "my-snprintf.h"
@@ -3021,8 +3029,74 @@ close_iconv(void *dummy)
 	iconv_close(m_iconv_gb_ucs4);
 	m_iconv_gb_ucs4 = (iconv_t)(-1);
     }
+    if (m_iconv_jis_ucs4 != (iconv_t)(-1)) {
+	iconv_close(m_iconv_jis_ucs4);
+	m_iconv_jis_ucs4 = (iconv_t)(-1);
+    }
+#endif /* HAVE_ICONV_H */
+}
+
+#ifdef PTEX
+/* convert a JIS char to unicode (UCS-4) using iconv() */
+uint32_t
+jis2unicode(wide_ubyte jis)
+{
+#if HAVE_ICONV_H
+    uint32_t u = 0;
+    unsigned char jis_seq[8] = { 
+	0x1b, 0x24, 0x42, /* JIS X 0208-1983 */
+	(unsigned char)(jis >> 8), (unsigned char)jis,
+	0x1b, 0x28, 0x42, /* ASCII */
+    };
+    unsigned char unicode[4];
+    size_t from = sizeof jis_seq;
+    size_t to = sizeof unicode;
+    static Boolean initialized = False;
+    char *from_ptr = (char *)jis_seq;
+    char *to_ptr = (char *)unicode;
+
+    if (m_iconv_jis_ucs4 == (iconv_t)(-1)) {
+	if (initialized)
+	    return 0;
+	initialized = True;
+	m_iconv_jis_ucs4 = iconv_open(
+#ifdef WORDS_BIGENDIAN
+				     "UCS-4BE",
+#else
+				     "UCS-4LE",
+#endif
+				     "ISO-2022-JP");
+	if (m_iconv_jis_ucs4 == (iconv_t)(-1)) {
+	    XDVI_ERROR((stderr, "jis2unicode: iconv_open() failed: %s", strerror(errno)));
+	    return 0;
+	}
+    }
+    if (iconv(m_iconv_jis_ucs4, (iconv_char_pptrT)&from_ptr, &from, &to_ptr, &to) == (size_t)(-1)) {
+	XDVI_ERROR((stderr, "jis2unicode: can't convert JIS to unicode: %s", strerror(errno)));
+	return 0;
+    }
+    memcpy(&u, unicode, sizeof unicode);
+    return u;
+#elif HAVE_PTEXENC
+    uint32_t u = 0;
+    u = JIStoUCS2(jis);
+    if (u == 0) {
+	XDVI_ERROR((stderr, "jis2unicode: can't convert JIS (%04x) to unicode in ptexenc library", jis));
+    }
+    return u;
+#else /* !HAVE_ICONV_H && !HAVE_PTEXENC */
+    static Boolean warned = False;
+
+    if (!warned) {
+        popup_message(globals.widgets.top_level,
+                      MSG_WARN, NULL, "This version of xdvi has been compiled without iconv support - "
+                      "cannot convert Kanji character to UTF-8");
+        warned = True;
+    }
+    return 0;
 #endif /* HAVE_ICONV_H */
 }
+#endif /* PTEX */
 
 /* convert a CJK char to unicode (UCS-4) using iconv() */
 static uint32_t
@@ -3577,6 +3651,24 @@ guess_encoding(wide_ubyte ch, const char
     
     TRACE_FIND_VERBOSE((stderr, "guess_encoding: |%s|, char 0x%.4X", fontname, ch));
 
+#ifdef PTEX
+    if (iskanjifont(fontname)) {
+	struct ptexmap *map = getkanjifont(fontname);
+	switch (map->encoding) {
+	case ENC_JIS_H:
+	case ENC_JIS_V:
+	    TRACE_FIND_VERBOSE((stderr, "guess_encoding: Kanji fonts (JIS encoding)"));
+	    return jis2unicode(ch);
+	case ENC_UNICODE_H:
+	case ENC_UNICODE_V:
+	    TRACE_FIND_VERBOSE((stderr, "guess_encoding: Kanji fonts (Unicode encoding)"));
+	    return ch;
+	default:
+	    TRACE_FIND_VERBOSE((stderr, "guess_encoding: Kanji fonts (Unsupported encoding)"));
+	    return '?';
+	}
+    }
+#endif  /* PTEX */
     /* our encoding vectors only have size 256 */
     if (ch > 255) {
 	XDVI_WARNING((stderr, "guess_encoding: font index %lu too large", (unsigned long)ch));
