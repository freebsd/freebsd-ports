--- Makefile.inc.orig	Tue Feb 17 08:55:35 2004
+++ Makefile.inc	Tue Feb 17 08:54:46 2004
@@ -22,7 +22,7 @@
 LIBDIRS += $(UDIR)/build/src/.libs
 endif
 ifneq ($(strip $(wildcard $(UDIR))),)
-LIBDIRS += $(UDIR)
+LIBDIRS += $(UDIR)/lib
 DOS_LIBDIRS := $(DOS_LIBDIRS);$(UDIR)
 endif
 
