--- lib/usual/endian.h.orig	2010-12-14 07:35:50.000000000 +0100
+++ lib/usual/endian.h	2011-01-12 16:01:08.148625395 +0100
@@ -157,6 +157,7 @@
 /*
  * Read LE/BE values from memory.
  */
+#ifndef __FreeBSD__
 
 #define _DEC(name, typ, decode) \
 static inline typ name(const void *p) { \
@@ -173,10 +174,14 @@
 _DEC(le64dec, uint64_t, le64toh)
 #undef _DEC
 
+#endif
+
 /*
  * Write LE/BE values to memory.
  */
 
+#ifndef __FreeBSD__
+
 #define _ENC(name, typ, encode) \
 static inline void name(void *p, typ val) { \
 	typ tmp = encode(val); \
@@ -190,4 +195,6 @@
 _ENC(le64enc, uint64_t, htole64)
 #undef _ENC
 
+#endif
+
 #endif	/* _USUAL_ENDIAN_H_ */
