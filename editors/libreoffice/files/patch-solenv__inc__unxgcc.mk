--- ./solenv/inc/unxgcc.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./solenv/inc/unxgcc.mk	2012-04-17 00:58:31.000000000 +0200
@@ -78,7 +78,7 @@
 # flags for the C++ Compiler
 CFLAGSCC= -pipe $(ARCH_FLAGS)
 # Flags for enabling exception handling
-CFLAGSEXCEPTIONS=-fexceptions -fno-enforce-eh-specs
+CFLAGSEXCEPTIONS=-fexceptions
 # Flags for disabling exception handling
 CFLAGS_NO_EXCEPTIONS=-fno-exceptions
 
@@ -88,7 +88,7 @@
 CFLAGSCXX+=-fvisibility-inlines-hidden
 .ENDIF # "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
 .IF "$(HAVE_CXX0X)" == "TRUE"
-CFLAGSCXX+=-std=c++0x
+CFLAGSCXX+=-std=gnu++0x
 .IF "$(GCCNUMVER)" <= "000400059999"
 CFLAGSCXX+=-Wno-deprecated-declarations
 .ENDIF
