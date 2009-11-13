--- make/lib.mak.orig	2009-11-13 21:10:07.000000000 +0800
+++ make/lib.mak	2009-11-13 21:16:47.000000000 +0800
@@ -97,8 +97,12 @@
     ifeq ($(OSTYPE),mingw)
       LDSOOPTS += -Wl,--kill-at
     else
-      ifneq ($(OSTYPE),Darwin)
-        LDSOOPTS += -Wl,-soname,$(LIB_SONAME)
+      ifeq ($(OSTYPE),FreeBSD)
+        LDSOOPTS += -Wl,-soname,$(subst .$(LIB_SUFFIX),,$(LIB_FILENAME))-$(MAJOR_VERSION).$(MINOR_VERSION).$(LIB_SUFFIX).$(BUILD_NUMBER)
+      else
+        ifneq ($(OSTYPE),Darwin)
+          LDSOOPTS += -Wl,-soname,$(LIB_SONAME)
+        endif
       endif
     endif
   endif
