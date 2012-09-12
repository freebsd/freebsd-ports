--- ./src/wavpack_local.h.orig	2009-12-01 04:24:50.000000000 +0000
+++ ./src/wavpack_local.h	2012-09-12 21:12:47.161974704 +0100
@@ -11,6 +11,10 @@
 #ifndef WAVPACK_LOCAL_H
 #define WAVPACK_LOCAL_H
 
+#ifndef __has_builtin
+#define __has_builtin(x) 0
+#endif
+
 #if defined(WIN32)
 #define FASTCALL __fastcall
 #else
@@ -768,7 +772,7 @@
 #define _m_paddd(m1, m2) __builtin_ia32_paddd (m1, m2)
 #define _m_pcmpeqd(m1, m2) __builtin_ia32_pcmpeqd (m1, m2)
 
-#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 4) || __GNUC__ > 4
+#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 4) || __GNUC__ > 4 || __has_builtin(__builtin_ia32_pslldi)
 #	define _m_pslldi(m1, m2) __builtin_ia32_pslldi ((__m64)m1, m2)
 #	define _m_psradi(m1, m2) __builtin_ia32_psradi ((__m64)m1, m2)
 #	define _m_psrldi(m1, m2) __builtin_ia32_psrldi ((__m64)m1, m2)
