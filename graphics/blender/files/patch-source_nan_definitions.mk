--- source/nan_definitions.mk.orig	Tue Sep 18 06:58:49 2007
+++ source/nan_definitions.mk	Thu Oct  4 22:00:38 2007
@@ -55,9 +55,9 @@
     export NAN_LIBDIR ?= $(NANBLENDERHOME)/../lib
     export NAN_OBJDIR ?= $(NANBLENDERHOME)/obj
     # Library Config_Guess DIRectory
-    export LCGDIR = $(NAN_LIBDIR)/$(CONFIG_GUESS)
+    export LCGDIR = $(NAN_LIBDIR)/freebsd
     # Object Config_Guess DIRectory
-    export OCGDIR = $(NAN_OBJDIR)/$(CONFIG_GUESS)
+    export OCGDIR = $(NAN_OBJDIR)/freebsd
 
     # Determines what targets are built
     export WITH_BF_DYNAMICOPENGL ?= true
