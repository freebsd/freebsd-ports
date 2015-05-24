--- native/base/basictypes.h.orig	2015-02-23 23:22:58 UTC
+++ native/base/basictypes.h
@@ -87,7 +87,7 @@ inline uint64 swap64(uint64 _data) {retu
 inline uint16 swap16(uint16 _data) {return bswap_16(_data);}
 inline uint32 swap32(uint32 _data) {return bswap_32(_data);}
 inline uint64 swap64(uint64 _data) {return bswap_64(_data);}
-#elif defined(__FreeBSD__)
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
 #include <sys/endian.h>
 inline uint16 swap16(uint16 _data) {return bswap16(_data);}
 inline uint32 swap32(uint32 _data) {return bswap32(_data);}
