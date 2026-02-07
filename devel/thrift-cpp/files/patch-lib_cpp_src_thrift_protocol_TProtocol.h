--- lib/cpp/src/thrift/protocol/TProtocol.h.orig	2025-08-24 09:28:32 UTC
+++ lib/cpp/src/thrift/protocol/TProtocol.h
@@ -146,7 +146,7 @@ static inline To bitwise_cast(From from) {
 #  define THRIFT_ntohll(n) (n)
 #  define THRIFT_htonll(n) (n)
 # endif
-# if defined(__GNUC__) && defined(__GLIBC__)
+# if defined(__GNUC__)
 #  include <byteswap.h>
 #  define THRIFT_htolell(n) bswap_64(n)
 #  define THRIFT_letohll(n) bswap_64(n)
