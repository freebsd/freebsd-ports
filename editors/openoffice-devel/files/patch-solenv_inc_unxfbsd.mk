--- solenv/inc/unxfbsd.mk.orig	2017-01-23 03:29:47 UTC
+++ solenv/inc/unxfbsd.mk
@@ -105,10 +105,15 @@ CFLAGSEXCEPTIONS=-fexceptions -fno-enforce-eh-specs
 CFLAGS_NO_EXCEPTIONS=-fno-exceptions
 
 # -fpermissive should be removed as soon as possible
-CFLAGSCXX= -pipe $(ARCH_FLAGS) 
+CFLAGSCXX= -pipe $(ARCH_FLAGS) -std=gnu++98
 .IF "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
 CFLAGSCXX += -fvisibility-inlines-hidden
 .ENDIF # "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
+
+.IF "$(CPUNAME)" == "INTEL" || "$(CPUNAME)" == "X86_64"
+CFLAGSCC += -fstack-protector
+CFLAGSCXX += -fstack-protector
+.ENDIF
 
 # Compiler flags for compiling static object in multi threaded environment with graphical user interface
 CFLAGSOBJGUIMT=
