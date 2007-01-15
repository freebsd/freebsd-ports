--- build/ref_newgl.mk.orig	Mon Jan 15 12:13:34 2007
+++ build/ref_newgl.mk	Mon Jan 15 12:20:31 2007
@@ -9,9 +9,9 @@
 VPATH += $(INSTALLDIR)/ref_newgl \
 	 $(INSTALLDIR)/ref_shared
 	
-LDFLAGS += -lm -ljpeg -shared -fPIC
+LDFLAGS += -lm -ljpeg -shared
 CFLAGS += -DOPENGL_RENDERER -DTRUECOLOR_RENDERER -DUSE_LIBJPEG
-CFLAGS_LINUX += -DUSE_LIBPNG
+CFLAGS_LINUX += -DUSE_LIBPNG -fPIC
 LDFLAGS_LINUX += -lpng
 
 ifeq (win32,$(TARGETOS))
