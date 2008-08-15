--- reggnu.c.orig	2008-08-15 20:48:50.000000000 +0400
+++ reggnu.c	2008-08-15 20:49:03.000000000 +0400
@@ -254,3 +254,137 @@
   }
 #endif
 }
+typedef unsigned int (*mbc_startpos_func_t) _((const char *string, unsigned int pos));
+
+static unsigned int asc_startpos _((const char *string, unsigned int pos));
+static unsigned int euc_startpos _((const char *string, unsigned int pos));
+static unsigned int sjis_startpos _((const char *string, unsigned int pos));
+static unsigned int utf8_startpos _((const char *string, unsigned int pos));
+
+/* adjust startpos value to the position between characters. */
+int
+re_mbc_startpos(string, size, startpos, range)
+     const char *string;
+     int size, startpos, range;
+{
+  OnigEncoding current_enc = onigenc_get_default_encoding();
+  int i;
+
+  if (current_enc == ONIG_ENCODING_ASCII)
+	i = asc_startpos(string, startpos);
+  else if (current_enc == ONIG_ENCODING_EUC_JP)
+	i = euc_startpos(string, startpos);
+  else if (current_enc == ONIG_ENCODING_SJIS)
+	i = sjis_startpos(string, startpos);
+  else if (current_enc == ONIG_ENCODING_UTF8)
+	i = utf8_startpos(string, startpos);
+  else
+	return (-1);
+
+  if (i < startpos) {
+    if (range > 0) {
+      startpos = i + mbclen(string[i]);
+    }
+    else {
+      int len = mbclen(string[i]);
+      if (i + len <= startpos)
+	startpos = i + len;
+      else
+	startpos = i;
+    }
+  }
+  return startpos;
+}
+
+#define mbc_isfirst(t, c) (t)[(unsigned char)(c)]
+#define mbc_len(t, c)     ((t)[(unsigned char)(c)]+1)
+
+static unsigned int
+asc_startpos(string, pos)
+     const char *string;
+     unsigned int pos;
+{
+  return pos;
+}
+
+#define euc_islead(c)  ((unsigned char)((c) - 0xa1) > 0xfe - 0xa1)
+#define euc_mbclen(c)  mbc_len(mbctab_euc, (c))
+static unsigned int
+euc_startpos(string, pos)
+     const char *string;
+     unsigned int pos;
+{
+  unsigned int i = pos, w;
+
+  while (i > 0 && !euc_islead(string[i])) {
+    --i;
+  }
+  if (i == pos || i + (w = euc_mbclen(string[i])) > pos) {
+    return i;
+  }
+  i += w;
+  return i + ((pos - i) & ~1);
+}
+
+static const unsigned char mbctab_sjis_trail[] = { /* 0x40-0x7E,0x80-0xFC */
+  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
+  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
+  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
+  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
+  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0
+};
+
+#define sjis_isfirst(c) mbc_isfirst(mbctab_sjis, (c))
+#define sjis_istrail(c) mbctab_sjis_trail[(unsigned char)(c)]
+#define sjis_mbclen(c)  mbc_len(mbctab_sjis, (c))
+static unsigned int
+sjis_startpos(string, pos)
+     const char *string;
+     unsigned int pos;
+{
+  unsigned int i = pos, w;
+
+  if (i > 0 && sjis_istrail(string[i])) {
+    do {
+      if (!sjis_isfirst(string[--i])) {
+	++i;
+	break;
+      }
+    } while (i > 0);
+  }
+  if (i == pos || i + (w = sjis_mbclen(string[i])) > pos) {
+    return i;
+  }
+  i += w;
+  return i + ((pos - i) & ~1);
+}
+
+#define utf8_islead(c)  ((unsigned char)((c) & 0xc0) != 0x80)
+#define utf8_mbclen(c)  mbc_len(mbctab_utf8, (c))
+static unsigned int
+utf8_startpos(string, pos)
+     const char *string;
+     unsigned int pos;
+{
+  unsigned int i = pos, w;
+
+  while (i > 0 && !utf8_islead(string[i])) {
+    --i;
+  }
+  if (i == pos || i + (w = utf8_mbclen(string[i])) > pos) {
+    return i;
+  }
+  return i + w;
+}
+#undef utf8_islead
