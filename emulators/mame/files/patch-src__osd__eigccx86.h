--- src/osd/eigccx86.h.orig	2015-05-24 15:52:19 UTC
+++ src/osd/eigccx86.h
@@ -42,7 +42,7 @@ union _x86_union
     multiply and return the full 64 bit result
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mul_32x32 _mul_32x32
 INLINE INT64 ATTR_CONST ATTR_FORCE_INLINE
 _mul_32x32(INT32 a, INT32 b)
@@ -68,7 +68,7 @@ _mul_32x32(INT32 a, INT32 b)
     result
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mulu_32x32 _mulu_32x32
 INLINE UINT64 ATTR_CONST ATTR_FORCE_INLINE
 _mulu_32x32(UINT32 a, UINT32 b)
@@ -145,7 +145,7 @@ _mulu_32x32_hi(UINT32 a, UINT32 b)
     result to 32 bits
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mul_32x32_shift _mul_32x32_shift
 INLINE INT32 ATTR_CONST ATTR_FORCE_INLINE
 _mul_32x32_shift(INT32 a, INT32 b, UINT8 shift)
@@ -175,7 +175,7 @@ _mul_32x32_shift(INT32 a, INT32 b, UINT8
     result to 32 bits
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mulu_32x32_shift _mulu_32x32_shift
 INLINE UINT32 ATTR_CONST ATTR_FORCE_INLINE
 _mulu_32x32_shift(UINT32 a, UINT32 b, UINT8 shift)
@@ -203,7 +203,7 @@ _mulu_32x32_shift(UINT32 a, UINT32 b, UI
     divide and return the 32 bit quotient
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define div_64x32 _div_64x32
 INLINE INT32 ATTR_CONST ATTR_FORCE_INLINE
 _div_64x32(INT64 a, INT32 b)
@@ -230,7 +230,7 @@ _div_64x32(INT64 a, INT32 b)
     divide and return the 32 bit quotient
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define divu_64x32 _divu_64x32
 INLINE UINT32 ATTR_CONST ATTR_FORCE_INLINE
 _divu_64x32(UINT64 a, UINT32 b)
@@ -258,7 +258,7 @@ _divu_64x32(UINT64 a, UINT32 b)
     32 bit remainder
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define div_64x32_rem _div_64x32_rem
 INLINE INT32 ATTR_FORCE_INLINE
 _div_64x32_rem(INT64 dividend, INT32 divisor, INT32 *remainder)
@@ -286,7 +286,7 @@ _div_64x32_rem(INT64 dividend, INT32 div
     and 32 bit remainder
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define divu_64x32_rem _divu_64x32_rem
 INLINE UINT32 ATTR_FORCE_INLINE
 _divu_64x32_rem(UINT64 dividend, UINT32 divisor, UINT32 *remainder)
@@ -337,7 +337,7 @@ _divu_64x32_rem(UINT64 dividend, UINT32 
     division, and returning the 32 bit quotient
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define div_32x32_shift _div_32x32_shift
 INLINE INT32 ATTR_CONST ATTR_FORCE_INLINE
 _div_32x32_shift(INT32 a, INT32 b, UINT8 shift)
@@ -369,7 +369,7 @@ _div_32x32_shift(INT32 a, INT32 b, UINT8
     division, and returning the 32 bit quotient
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define divu_32x32_shift _divu_32x32_shift
 INLINE UINT32 ATTR_CONST ATTR_FORCE_INLINE
 _divu_32x32_shift(UINT32 a, UINT32 b, UINT8 shift)
@@ -400,7 +400,7 @@ _divu_32x32_shift(UINT32 a, UINT32 b, UI
     divide and return the 32 bit remainder
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define mod_64x32 _mod_64x32
 INLINE INT32 ATTR_CONST ATTR_FORCE_INLINE
 _mod_64x32(INT64 a, INT32 b)
@@ -427,7 +427,7 @@ _mod_64x32(INT64 a, INT32 b)
     divide and return the 32 bit remainder
 -------------------------------------------------*/
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 #define modu_64x32 _modu_64x32
 INLINE UINT32 ATTR_CONST ATTR_FORCE_INLINE
 _modu_64x32(UINT64 a, UINT32 b)
@@ -563,7 +563,7 @@ _compare_exchange32(INT32 volatile *ptr,
     return the previous value at 'ptr'.
 -------------------------------------------------*/
 
-#ifdef __x86_64__
+#if defined(__amd64__) || defined(__x86_64__)
 #define compare_exchange64 _compare_exchange64
 INLINE INT64 ATTR_NONNULL(1) ATTR_FORCE_INLINE
 _compare_exchange64(INT64 volatile *ptr, INT64 compare, INT64 exchange)
@@ -693,7 +693,7 @@ _atomic_decrement32(INT32 volatile *ptr)
 
 #define get_profile_ticks _get_profile_ticks
 
-#ifndef __x86_64__
+#if !defined(__amd64__) && !defined(__x86_64__)
 INLINE UINT64 ATTR_UNUSED ATTR_FORCE_INLINE _get_profile_ticks(void)
 {
 	UINT64 result;
