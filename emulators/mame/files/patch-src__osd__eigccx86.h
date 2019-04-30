--- src/osd/eigccx86.h.orig	2018-02-27 15:59:06 UTC
+++ src/osd/eigccx86.h
@@ -31,7 +31,7 @@
     multiply and return the full 64 bit result
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mul_32x32 _mul_32x32
 inline int64_t ATTR_CONST ATTR_FORCE_INLINE
 _mul_32x32(int32_t a, int32_t b)
@@ -55,7 +55,7 @@ _mul_32x32(int32_t a, int32_t b)
     result
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mulu_32x32 _mulu_32x32
 inline uint64_t ATTR_CONST ATTR_FORCE_INLINE
 _mulu_32x32(uint32_t a, uint32_t b)
@@ -126,7 +126,7 @@ _mulu_32x32_hi(uint32_t a, uint32_t b)
     result to 32 bits
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mul_32x32_shift _mul_32x32_shift
 inline int32_t ATTR_CONST ATTR_FORCE_INLINE
 _mul_32x32_shift(int32_t a, int32_t b, uint8_t shift)
@@ -156,7 +156,7 @@ _mul_32x32_shift(int32_t a, int32_t b, u
     result to 32 bits
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mulu_32x32_shift _mulu_32x32_shift
 inline uint32_t ATTR_CONST ATTR_FORCE_INLINE
 _mulu_32x32_shift(uint32_t a, uint32_t b, uint8_t shift)
@@ -184,7 +184,7 @@ _mulu_32x32_shift(uint32_t a, uint32_t b
     divide and return the 32 bit quotient
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define div_64x32 _div_64x32
 inline int32_t ATTR_CONST ATTR_FORCE_INLINE
 _div_64x32(int64_t a, int32_t b)
@@ -211,7 +211,7 @@ _div_64x32(int64_t a, int32_t b)
     divide and return the 32 bit quotient
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define divu_64x32 _divu_64x32
 inline uint32_t ATTR_CONST ATTR_FORCE_INLINE
 _divu_64x32(uint64_t a, uint32_t b)
@@ -244,7 +244,7 @@ inline int32_t ATTR_FORCE_INLINE
 _div_64x32_rem(int64_t dividend, int32_t divisor, int32_t *remainder)
 {
 	int32_t quotient;
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 
 	// Throws arithmetic exception if result doesn't fit in 32 bits
 	__asm__ (
@@ -287,7 +287,7 @@ inline uint32_t ATTR_FORCE_INLINE
 _divu_64x32_rem(uint64_t dividend, uint32_t divisor, uint32_t *remainder)
 {
 	uint32_t quotient;
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 
 	// Throws arithmetic exception if result doesn't fit in 32 bits
 	__asm__ (
@@ -325,7 +325,7 @@ _divu_64x32_rem(uint64_t dividend, uint3
     division, and returning the 32 bit quotient
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define div_32x32_shift _div_32x32_shift
 inline int32_t ATTR_CONST ATTR_FORCE_INLINE
 _div_32x32_shift(int32_t a, int32_t b, uint8_t shift)
@@ -357,7 +357,7 @@ _div_32x32_shift(int32_t a, int32_t b, u
     division, and returning the 32 bit quotient
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define divu_32x32_shift _divu_32x32_shift
 inline uint32_t ATTR_CONST ATTR_FORCE_INLINE
 _divu_32x32_shift(uint32_t a, uint32_t b, uint8_t shift)
@@ -388,7 +388,7 @@ _divu_32x32_shift(uint32_t a, uint32_t b
     divide and return the 32 bit remainder
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mod_64x32 _mod_64x32
 inline int32_t ATTR_CONST ATTR_FORCE_INLINE
 _mod_64x32(int64_t a, int32_t b)
@@ -415,7 +415,7 @@ _mod_64x32(int64_t a, int32_t b)
     divide and return the 32 bit remainder
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define modu_64x32 _modu_64x32
 inline uint32_t ATTR_CONST ATTR_FORCE_INLINE
 _modu_64x32(uint64_t a, uint32_t b)
