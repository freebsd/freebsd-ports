--- solenv/inc/unxfbsd.mk.orig	2017-11-27 13:50:28 UTC
+++ solenv/inc/unxfbsd.mk
@@ -96,7 +96,7 @@ CFLAGSEXCEPTIONS=-fexceptions -fno-enforce-eh-specs
 CFLAGS_NO_EXCEPTIONS=-fno-exceptions
 
 # -fpermissive should be removed as soon as possible
-CFLAGSCXX= -pipe $(ARCH_FLAGS) 
+CFLAGSCXX= -pipe $(ARCH_FLAGS) -std=gnu++98
 .IF "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
 CFLAGSCXX += -fvisibility-inlines-hidden
 .ENDIF # "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
