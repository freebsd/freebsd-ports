--- solenv/inc/unxfbsdx.mk.orig	2011-07-23 08:03:44.000000000 +0300
+++ solenv/inc/unxfbsdx.mk	2011-07-23 08:26:13.000000000 +0300
@@ -25,25 +25,8 @@
 #
 #*************************************************************************
 
-#
-# FreBSD/amd64 specific defines
-#
+# FreeBSD/amd64 specific defines
 
+.INCLUDE : unxfbsd.mk
 CDEFS+=-DX86_64
-
-# architecture dependent flags for the C and C++ compiler that can be changed by
-# exporting the variable ARCH_FLAGS="..." in the shell, which is used to start build
-.IF "$(CPUNAME)" == "X86_64"
-ARCH_FLAGS*=
-.ENDIF
-
-# Compiler flags for enabling optimizations
-.IF "$(PRODUCT)"!=""
-CFLAGSOPT=-O2 -fno-strict-aliasing		# optimizing for products
-.ELSE 	# "$(PRODUCT)"!=""
-CFLAGSOPT=   					# no optimizing for non products
-.ENDIF	# "$(PRODUCT)"!=""
-
-# platform specific identifier for shared libs
-DLLPOSTFIX=fx
 BUILD64=1
