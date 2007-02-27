--- source/nan_definitions.mk.orig	Wed Nov 22 14:05:35 2006
+++ source/nan_definitions.mk	Tue Feb 20 03:38:18 2007
@@ -55,9 +55,9 @@
     export NAN_LIBDIR ?= $(NANBLENDERHOME)/../lib
     export NAN_OBJDIR ?= $(NANBLENDERHOME)/obj
     # Library Config_Guess DIRectory
-    export LCGDIR = $(NAN_LIBDIR)/$(CONFIG_GUESS)
+    export LCGDIR = $(NAN_LIBDIR)/freebsd
     # Object Config_Guess DIRectory
-    export OCGDIR = $(NAN_OBJDIR)/$(CONFIG_GUESS)
+    export OCGDIR = $(NAN_OBJDIR)/freebsd
 
     export NAN_MOTO ?= $(LCGDIR)/moto
 ifeq ($(FREE_WINDOWS), true)
@@ -291,6 +291,7 @@
 
     # enable freetype2 support for text objects
     # export WITH_FREETYPE2 ?= true
+    export NAN_NO_KETSJI=true
 
   else
   ifeq ($(OS),irix)
