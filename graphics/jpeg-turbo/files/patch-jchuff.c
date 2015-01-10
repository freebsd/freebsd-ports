--- jchuff.c.orig	2013-09-28 03:23:49 UTC
+++ jchuff.c
@@ -391,7 +391,16 @@ dump_buffer (working_state * state)
 #endif
 
 
-#define BUFSIZE (DCTSIZE2 * 2)
+/* Although it is exceedingly rare, it is possible for a Huffman-encoded
+ * coefficient block to be larger than the 128-byte unencoded block.  For each
+ * of the 64 coefficients, PUT_BITS is invoked twice, and each invocation can
+ * theoretically store 16 bits (for a maximum of 2048 bits or 256 bytes per
+ * encoded block.)  If, for instance, one artificially sets the AC
+ * coefficients to alternating values of 32767 and -32768 (using the JPEG
+ * scanning order-- 1, 8, 16, etc.), then this will produce an encoded block
+ * larger than 200 bytes.
+ */
+#define BUFSIZE (DCTSIZE2 * 4)
 
 #define LOAD_BUFFER() { \
   if (state->free_in_buffer < BUFSIZE) { \
