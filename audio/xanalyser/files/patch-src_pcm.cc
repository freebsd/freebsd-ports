--- src/pcm.cc.orig	Sun Oct 29 20:39:22 2006
+++ src/pcm.cc	Sun Oct 29 20:47:16 2006
@@ -9,6 +9,8 @@
 #include <stdlib.h>
 #ifdef __NetBSD__
 #  include <machine/byte_swap.h>
+#elif __FreeBSD__
+#  include <sys/endian.h>
 #else
 #  include <byteswap.h>
 #endif
@@ -163,7 +165,7 @@
 	case S16: {
 	    int16_t* tmp_buffer = (int16_t*) buffer;
 	    for (size_t i = n; i != 0; i--) {
-#ifdef __NetBSD__
+#if defined  (__NetBSD__) || (__FreeBSD__)
 		*tmp_buffer = bswap16 (*tmp_buffer);
 #else
 		*tmp_buffer = bswap_16 (*tmp_buffer);
@@ -175,7 +177,7 @@
 	case S32: {
 	    int32_t* tmp_buffer = (int32_t*) buffer;
 	    for (size_t i = n; i != 0; i--) {
-#ifdef __NetBSD__
+#if defined (__NetBSD__) || (__FreeBSD__)
 		*tmp_buffer = bswap32 (*tmp_buffer);
 #else
 		*tmp_buffer = bswap_32 (*tmp_buffer);
@@ -191,7 +193,7 @@
 PCM::uint16_to_le (uint16_t i) const
 {
 #if __BYTE_ORDER == __BIG_ENDIAN
-#  ifdef __NetBSD__
+#  if defined (__NetBSD__) || (__FreeBSD__)
     return bswap16 (i);
 #  else
     return bswap_16 (i);
@@ -206,7 +208,7 @@
 PCM::uint32_to_le (uint32_t i) const
 {
 #if __BYTE_ORDER == __BIG_ENDIAN
-#  ifdef __NetBSD__
+#  if defined  (__NetBSD__)||(__FreeBSD__)
     return bswap32 (i);
 #  else
     return bswap_32 (i);
