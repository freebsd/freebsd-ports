--- solenv/inc/unxfbsdi.mk.orig	2011-07-23 08:03:39.000000000 +0300
+++ solenv/inc/unxfbsdi.mk	2011-07-23 08:26:34.000000000 +0300
@@ -25,22 +25,7 @@
 #
 #*************************************************************************
 
-#
-# FreBSD/i386 specific defines
-#
- 
-CDEFS+=-DX86
-
-# architecture dependent flags for the C and C++ compiler that can be changed by
-# exporting the variable ARCH_FLAGS="..." in the shell, which is used to start build
-ARCH_FLAGS*=-mtune=pentiumpro
-
-# Compiler flags for enabling optimizations
-.IF "$(PRODUCT)"!=""
-CFLAGSOPT=-Os -fno-strict-aliasing		# optimizing for products
-.ELSE 	# "$(PRODUCT)"!=""
-CFLAGSOPT= 					# no optimizing for non products
-.ENDIF	# "$(PRODUCT)"!=""
+# FreeBSD/i386 specific defines
 
-# platform specific identifier for shared libs
-DLLPOSTFIX=fi
+.INCLUDE : unxfbsd.mk
+CDEFS+=-DX86 
