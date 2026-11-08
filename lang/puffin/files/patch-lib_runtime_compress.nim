--- lib/runtime/compress.nim.orig	2026-10-31 12:09:53 UTC
+++ lib/runtime/compress.nim
@@ -19,21 +19,15 @@ elif defined(bsd) or defined(freebsd) or defined(netbs
   {.passC: "-D_DARWIN_C_SOURCE".}
 elif defined(bsd) or defined(freebsd) or defined(netbsd) or defined(openbsd) or defined(dragonfly):
   {.passC: "-D__BSD_VISIBLE=1 -D_XOPEN_SOURCE=700".}
+{.passC: gorge("pkg-config --silence-errors --cflags libzstd bzip2").}
+{.passL: gorge("pkg-config --silence-errors --libs libzstd bzip2").}
 {.compile: "codec_c.c".}
-{.compile: "zstddeclib.c".}
 {.compile: "vendor-xz-embedded/xz_crc32.c".}
 {.compile: "vendor-xz-embedded/xz_crc64.c".}
 {.compile: "vendor-xz-embedded/xz_sha256.c".}
 {.compile: "vendor-xz-embedded/xz_dec_stream.c".}
 {.compile: "vendor-xz-embedded/xz_dec_lzma2.c".}
 {.compile: "vendor-xz-embedded/xz_dec_bcj.c".}
-{.compile: "bzlib.c".}
-{.compile: "decompress.c".}
-{.compile: "huffman.c".}
-{.compile: "crctable.c".}
-{.compile: "randtable.c".}
-{.compile: "compress.c".}
-{.compile: "blocksort.c".}
 
 proc cXzDecompress(input: pointer, inputLen: csize_t,
                    output: ptr pointer, outputLen: ptr csize_t): cint
