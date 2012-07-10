--- ./solenv/inc/unxgcc.mk.orig	2012-05-22 08:48:18.000000000 -0400
+++ ./solenv/inc/unxgcc.mk	2012-07-10 18:28:23.000000000 -0400
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
@@ -136,8 +136,8 @@
 # -Wshadow does not work for C with nested uses of pthread_cleanup_push:
 CFLAGSWARNBOTH=-Wall -Wextra -Wendif-labels
 CFLAGSWARNCC=$(CFLAGSWARNBOTH) -Wdeclaration-after-statement
-CFLAGSWARNCXX=$(CFLAGSWARNBOTH) -Wshadow -Wno-ctor-dtor-privacy \
-    -Wno-non-virtual-dtor
+CFLAGSWARNCXX=$(CFLAGSWARNBOTH) -Wno-ctor-dtor-privacy \
+    -Wno-non-virtual-dtor -Wno-unused-parameter
 CFLAGSWALLCC=$(CFLAGSWARNCC)
 CFLAGSWALLCXX=$(CFLAGSWARNCXX)
 CFLAGSWERRCC=-Werror -DLIBO_WERROR
