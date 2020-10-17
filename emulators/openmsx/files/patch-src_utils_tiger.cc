--- src/utils/tiger.cc.orig	2020-10-16 15:12:50 UTC
+++ src/utils/tiger.cc
@@ -662,9 +662,9 @@ static inline void initState(uint64_t state[3])
 static inline void returnState(uint64_t state[3])
 {
 	if (OPENMSX_BIGENDIAN) {
-		state[0] = Endian::bswap64(state[0]);
-		state[1] = Endian::bswap64(state[1]);
-		state[2] = Endian::bswap64(state[2]);
+		state[0] = Endian::byteswap64(state[0]);
+		state[1] = Endian::byteswap64(state[1]);
+		state[2] = Endian::byteswap64(state[2]);
 	}
 }
 
