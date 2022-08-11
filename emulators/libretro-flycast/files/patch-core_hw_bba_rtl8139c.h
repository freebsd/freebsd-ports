--- core/hw/bba/rtl8139c.h.orig	2021-06-18 06:17:55 UTC
+++ core/hw/bba/rtl8139c.h
@@ -58,6 +58,7 @@ struct MemoryRegion {
 /*
  * Byte swapping utilities
  */
+/*
 static inline uint16_t bswap16(uint16_t x)
 {
     return (((x & 0x00ff) << 8) |
@@ -71,6 +72,7 @@ static inline uint32_t bswap32(uint32_t x)
             ((x & 0x00ff0000U) >>  8) |
             ((x & 0xff000000U) >> 24));
 }
+*/
 #define glue(a, b) _glue(a, b)
 #define _glue(a, b) a ## b
 
