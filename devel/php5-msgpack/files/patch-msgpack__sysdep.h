--- ./msgpack/sysdep.h.orig	2011-10-06 05:01:16.000000000 +0400
+++ ./msgpack/sysdep.h	2012-05-28 15:06:00.762504244 +0400
@@ -36,20 +36,20 @@
 #include <stdbool.h>
 #endif
 
+
 #ifdef _WIN32
-#define _msgpack_atomic_counter_header <windows.h>
 typedef long _msgpack_atomic_counter_t;
 #define _msgpack_sync_decr_and_fetch(ptr) InterlockedDecrement(ptr)
 #define _msgpack_sync_incr_and_fetch(ptr) InterlockedIncrement(ptr)
-#elif defined(__GNUC__) && ((__GNUC__*10 + __GNUC_MINOR__) < 41)
-#define _msgpack_atomic_counter_header "gcc_atomic.h"
 #else
 typedef unsigned int _msgpack_atomic_counter_t;
 #define _msgpack_sync_decr_and_fetch(ptr) __sync_sub_and_fetch(ptr, 1)
 #define _msgpack_sync_incr_and_fetch(ptr) __sync_add_and_fetch(ptr, 1)
 #endif
 
+
 #ifdef _WIN32
+#include <winsock2.h>
 
 #ifdef __cplusplus
 /* numeric_limits<T>::min,max */
@@ -70,45 +70,15 @@
 #define __LITTLE_ENDIAN__
 #elif __BYTE_ORDER == __BIG_ENDIAN
 #define __BIG_ENDIAN__
-#elif _WIN32
-#define __LITTLE_ENDIAN__
 #endif
 #endif
 
-
 #ifdef __LITTLE_ENDIAN__
 
-#ifdef _WIN32
-#  if defined(ntohs)
-#    define _msgpack_be16(x) ntohs(x)
-#  elif defined(_byteswap_ushort) || (defined(_MSC_VER) && _MSC_VER >= 1400)
-#    define _msgpack_be16(x) ((uint16_t)_byteswap_ushort((unsigned short)x))
-#  else
-#    define _msgpack_be16(x) ( \
-        ((((uint16_t)x) <<  8) ) | \
-        ((((uint16_t)x) >>  8) ) )
-#  endif
-#else
-#  define _msgpack_be16(x) ntohs(x)
-#endif
-
-#ifdef _WIN32
-#  if defined(ntohl)
-#    define _msgpack_be32(x) ntohl(x)
-#  elif defined(_byteswap_ulong) || (defined(_MSC_VER) && _MSC_VER >= 1400)
-#    define _msgpack_be32(x) ((uint32_t)_byteswap_ulong((unsigned long)x))
-#  else
-#    define _msgpack_be32(x) \
-        ( ((((uint32_t)x) << 24)               ) | \
-          ((((uint32_t)x) <<  8) & 0x00ff0000U ) | \
-          ((((uint32_t)x) >>  8) & 0x0000ff00U ) | \
-          ((((uint32_t)x) >> 24)               ) )
-#  endif
-#else
-#  define _msgpack_be32(x) ntohl(x)
-#endif
+#define _msgpack_be16(x) ntohs(x)
+#define _msgpack_be32(x) ntohl(x)
 
-#if defined(_byteswap_uint64) || (defined(_MSC_VER) && _MSC_VER >= 1400)
+#if defined(_byteswap_uint64) || _MSC_VER >= 1400
 #  define _msgpack_be64(x) (_byteswap_uint64(x))
 #elif defined(bswap_64)
 #  define _msgpack_be64(x) bswap_64(x)
@@ -116,79 +86,34 @@
 #  define _msgpack_be64(x) __DARWIN_OSSwapInt64(x)
 #else
 #define _msgpack_be64(x) \
-    ( ((((uint64_t)x) << 56)                         ) | \
-      ((((uint64_t)x) << 40) & 0x00ff000000000000ULL ) | \
-      ((((uint64_t)x) << 24) & 0x0000ff0000000000ULL ) | \
-      ((((uint64_t)x) <<  8) & 0x000000ff00000000ULL ) | \
-      ((((uint64_t)x) >>  8) & 0x00000000ff000000ULL ) | \
-      ((((uint64_t)x) >> 24) & 0x0000000000ff0000ULL ) | \
-      ((((uint64_t)x) >> 40) & 0x000000000000ff00ULL ) | \
-      ((((uint64_t)x) >> 56)                         ) )
+	( ((((uint64_t)x) << 56) & 0xff00000000000000ULL ) | \
+	  ((((uint64_t)x) << 40) & 0x00ff000000000000ULL ) | \
+	  ((((uint64_t)x) << 24) & 0x0000ff0000000000ULL ) | \
+	  ((((uint64_t)x) <<  8) & 0x000000ff00000000ULL ) | \
+	  ((((uint64_t)x) >>  8) & 0x00000000ff000000ULL ) | \
+	  ((((uint64_t)x) >> 24) & 0x0000000000ff0000ULL ) | \
+	  ((((uint64_t)x) >> 40) & 0x000000000000ff00ULL ) | \
+	  ((((uint64_t)x) >> 56) & 0x00000000000000ffULL ) )
 #endif
 
-#define _msgpack_load16(cast, from) ((cast)( \
-        (((uint16_t)((uint8_t*)(from))[0]) << 8) | \
-        (((uint16_t)((uint8_t*)(from))[1])     ) ))
-
-#define _msgpack_load32(cast, from) ((cast)( \
-        (((uint32_t)((uint8_t*)(from))[0]) << 24) | \
-        (((uint32_t)((uint8_t*)(from))[1]) << 16) | \
-        (((uint32_t)((uint8_t*)(from))[2]) <<  8) | \
-        (((uint32_t)((uint8_t*)(from))[3])      ) ))
-
-#define _msgpack_load64(cast, from) ((cast)( \
-        (((uint64_t)((uint8_t*)(from))[0]) << 56) | \
-        (((uint64_t)((uint8_t*)(from))[1]) << 48) | \
-        (((uint64_t)((uint8_t*)(from))[2]) << 40) | \
-        (((uint64_t)((uint8_t*)(from))[3]) << 32) | \
-        (((uint64_t)((uint8_t*)(from))[4]) << 24) | \
-        (((uint64_t)((uint8_t*)(from))[5]) << 16) | \
-        (((uint64_t)((uint8_t*)(from))[6]) << 8)  | \
-        (((uint64_t)((uint8_t*)(from))[7])     )  ))
-
 #else
-
 #define _msgpack_be16(x) (x)
 #define _msgpack_be32(x) (x)
 #define _msgpack_be64(x) (x)
-
-#define _msgpack_load16(cast, from) ((cast)( \
-        (((uint16_t)((uint8_t*)from)[1]) << 8) | \
-        (((uint16_t)((uint8_t*)from)[0])     ) ))
-
-#define _msgpack_load32(cast, from) ((cast)( \
-        (((uint32_t)((uint8_t*)from)[3]) << 24) | \
-        (((uint32_t)((uint8_t*)from)[2]) << 16) | \
-        (((uint32_t)((uint8_t*)from)[1]) <<  8) | \
-        (((uint32_t)((uint8_t*)from)[0])      ) ))
-
-#define _msgpack_load64(cast, from) ((cast)( \
-        (((uint64_t)((uint8_t*)from)[7]) << 56) | \
-        (((uint64_t)((uint8_t*)from)[6]) << 48) | \
-        (((uint64_t)((uint8_t*)from)[5]) << 40) | \
-        (((uint64_t)((uint8_t*)from)[4]) << 32) | \
-        (((uint64_t)((uint8_t*)from)[3]) << 24) | \
-        (((uint64_t)((uint8_t*)from)[2]) << 16) | \
-        (((uint64_t)((uint8_t*)from)[1]) << 8)  | \
-        (((uint64_t)((uint8_t*)from)[0])     )  ))
 #endif
 
 
 #define _msgpack_store16(to, num) \
-    do { uint16_t val = _msgpack_be16(num); memcpy(to, &val, 2); } while(0)
+	do { uint16_t val = _msgpack_be16(num); memcpy(to, &val, 2); } while(0);
 #define _msgpack_store32(to, num) \
-    do { uint32_t val = _msgpack_be32(num); memcpy(to, &val, 4); } while(0)
+	do { uint32_t val = _msgpack_be32(num); memcpy(to, &val, 4); } while(0);
 #define _msgpack_store64(to, num) \
-    do { uint64_t val = _msgpack_be64(num); memcpy(to, &val, 8); } while(0)
+	do { uint64_t val = _msgpack_be64(num); memcpy(to, &val, 8); } while(0);
 
-/*
-#define _msgpack_load16(cast, from) \
-    ({ cast val; memcpy(&val, (char*)from, 2); _msgpack_be16(val); })
-#define _msgpack_load32(cast, from) \
-    ({ cast val; memcpy(&val, (char*)from, 4); _msgpack_be32(val); })
-#define _msgpack_load64(cast, from) \
-    ({ cast val; memcpy(&val, (char*)from, 8); _msgpack_be64(val); })
-*/
+
+#define _msgpack_load16(cast, from) ((cast)_msgpack_be16(*(uint16_t*)from))
+#define _msgpack_load32(cast, from) ((cast)_msgpack_be32(*(uint32_t*)from))
+#define _msgpack_load64(cast, from) ((cast)_msgpack_be64(*(uint64_t*)from))
 
 
 #endif /* msgpack/sysdep.h */
