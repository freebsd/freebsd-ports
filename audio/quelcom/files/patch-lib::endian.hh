--- lib/endian.hh.orig	Fri Feb 13 19:17:38 2004
+++ lib/endian.hh	Fri Feb 13 19:17:38 2004
@@ -0,0 +1,36 @@
+#ifndef _endian_hh_
+#define _endian_hh_
+
+/* quick and dirty endian conversion macros; applicable on big-endian
+ * architectures.  This works okay on big- and little-endian machines, but
+ * not on middle-endian ones, should the "Linux on PDP-11" thing ever get
+ * past the April Fool's stage.
+ */
+
+#if __BYTE_ORDER == __BIG_ENDIAN
+
+static inline u_int16_t letohs(u_int16_t n) { return (n<<8)|(n>>8); }
+static inline u_int32_t letohl(u_int32_t n) {
+  return (n<<24) | ((n&0xff00)<<8) | ((n&0xff0000)>>8) | (n>>24);
+}
+static inline u_int16_t htoles(u_int16_t n) { return letohs(n); }
+static inline u_int32_t htolel(u_int32_t n) { return letohl(n); }
+
+static inline int16_t letohs_s(int16_t n) {
+  unsigned char *p = (unsigned char *)&n, tmp;
+  tmp = p[0]; p[0] = p[1]; p[1] = tmp;
+  return n;
+}
+static inline int16_t htoles_s(int16_t n) { return letohs_s(n); }
+#elif __BYTE_ORDER == __LITTLE_ENDIAN
+static inline u_int16_t letohs(u_int16_t n) { return n; }
+static inline u_int32_t letohl(u_int32_t n) { return n; }
+static inline u_int16_t htoles(u_int16_t n) { return n; }
+static inline u_int32_t htolel(u_int32_t n) { return n; }
+
+static inline int16_t letohs_s(int16_t n) { return n; }
+static inline int16_t htoles_s(int16_t n) { return n; }
+#endif
+
+#endif
+
