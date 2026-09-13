--- s7.c.orig	2026-07-07 00:00:00 UTC
+++ s7.c
@@ -888,6 +888,18 @@
   union {
     s7_uint u64_type;             /* type info */
     s7_int s64_type;
+#if (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
+    struct {
+      uint8_t type_pad[7];
+      uint8_t type_field;
+    };
+    struct {
+      uint16_t high_bits;
+      uint16_t opt_bits;
+      uint16_t mid_bits;
+      uint16_t low_bits;
+    } bits;
+#else
     uint8_t type_field;
     struct {
       uint16_t low_bits;          /* 8 bits for type (type_field above, pair?/string? etc, 6 bits in use), 8 flag bits */
@@ -895,6 +907,7 @@
       uint16_t opt_bits;          /* 16 bits for opcode (eval choice), 10 in use) */
       uint16_t high_bits;         /* 16 more flag bits */
     } bits;
+#endif
   } tf;
   union {
 
