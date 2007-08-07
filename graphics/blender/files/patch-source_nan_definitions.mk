--- source/nan_definitions.mk.orig	Wed Nov 22 11:05:35 2006
+++ source/nan_definitions.mk	Wed Mar 21 21:24:37 2007
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
@@ -132,7 +132,7 @@
 	  export NAN_OPENEXR_LIBS ?= $(NAN_OPENEXR)/lib/libIlmImf.a $(NAN_OPENEXR)/lib/libHalf.a $(NAN_OPENEXR)/lib/libIex.a
         else
           export NAN_OPENEXR ?= /usr/local
-	  export NAN_OPENEXR_LIBS ?= $(NAN_OPENEXR)/lib/libIlmImf.a $(NAN_OPENEXR)/lib/libHalf.a $(NAN_OPENEXR)/lib/libIex.a
+	  export NAN_OPENEXR_LIBS ?= $(NAN_OPENEXR)/lib/libIlmImf.a $(NAN_OPENEXR)/lib/libIlmThread.a $(NAN_OPENEXR)/lib/libHalf.a $(NAN_OPENEXR)/lib/libIex.a
         endif
       endif
       export NAN_OPENEXR_INC ?= -I$(NAN_OPENEXR)/include -I$(NAN_OPENEXR)/include/OpenEXR
@@ -291,6 +291,7 @@
 
     # enable freetype2 support for text objects
     # export WITH_FREETYPE2 ?= true
+    export NAN_NO_KETSJI=true
 
   else
   ifeq ($(OS),irix)
