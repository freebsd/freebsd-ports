--- pigz.c.orig	2022-01-17 19:06:15 UTC
+++ pigz.c
@@ -558,9 +558,7 @@ local struct {
     int procs;              // maximum number of compression threads (>= 1)
     int setdict;            // true to initialize dictionary in each thread
     size_t block;           // uncompressed input size per thread (>= 32K)
-#ifndef NOTHREAD
     crc_t shift;            // pre-calculated CRC-32 shift for length block
-#endif
 
     // saved gzip/zip header data for decompression, testing, and listing
     time_t stamp;           // time stamp from gzip header
@@ -1338,9 +1336,6 @@ local long zlib_vernum(void) {
     return left < 2 ? num << (left << 2) : -1;
 }
 
-#ifndef NOTHREAD
-// -- threaded portions of pigz --
-
 // -- check value combination routines for parallel calculation --
 
 #define COMB(a,b,c) (g.form == 1 ? adler32_comb(a,b,c) : crc32_comb(a,b,c))
@@ -1421,6 +1416,9 @@ local unsigned long adler32_comb(unsigned long adler1,
     return sum1 | (sum2 << 16);
 }
 
+#ifndef NOTHREAD
+// -- threaded portions of pigz --
+
 // -- pool of spaces for buffer management --
 
 // These routines manage a pool of spaces. Each pool specifies a fixed size
@@ -4337,11 +4335,11 @@ local void defaults(void) {
     ZopfliInitOptions(&g.zopts);
 #endif
     g.block = 131072UL;             // 128K
+    g.shift = x2nmodp(g.block, 3);
 #ifdef NOTHREAD
     g.procs = 1;
 #else
     g.procs = nprocs(8);
-    g.shift = x2nmodp(g.block, 3);
 #endif
     g.rsync = 0;                    // don't do rsync blocking
     g.setdict = 1;                  // initialize dictionary each thread
