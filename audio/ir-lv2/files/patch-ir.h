--- ir.h.orig	2013-09-10 06:27:31 UTC
+++ ir.h
@@ -35,6 +35,9 @@
 #define BSIZE_SR    0x1000      /* Blocksize for SRC */
 #define MAXSIZE 0x00100000  /* Max. available convolver size of zita-convolver */
 
+#define exp10(x) pow(10., x) // TODO not as good as exp10()?
+#define exp10f(x) powf(10., x) // TODO not as good as exp10f()?
+
 #define DB_CO(g) ((g) > -90.0f ? exp10f((g) * 0.05f) : 0.0f)
 #define CO_DB(g) ((g) > 0.0f ? 20.0f * log10f(g) : -90.0f)
 
