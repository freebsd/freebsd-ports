--- XMP-Toolkit-SDK-4.4.2/source/common/EndianUtils.hpp.orig	2008-10-06 07:18:58 UTC
+++ XMP-Toolkit-SDK-4.4.2/source/common/EndianUtils.hpp
@@ -32,8 +32,13 @@
 	#endif
 #elif XMP_UNIXBuild
 	#ifndef kBigEndianHost	// Typically in the makefile for generic UNIX.
-		#if __GNUC__ && (__i386__ || __x86_64__)
-			#define kBigEndianHost 0
+		#ifdef __FreeBSD__
+			#include <sys/endian.h>
+			#if _BYTE_ORDER == _LITTLE_ENDIAN
+				#define kBigEndianHost 0
+			#else // _BYTE_ORDER == _BIG_ENDIAN
+				#define kBigEndianHost 1
+			#endif
 		#else
 			#error "Must define kBigEndianHost as 0 or 1 in the makefile."
 		#endif
