--- asimage/Module.mk.orig	Sat Dec  9 23:53:19 2006
+++ asimage/Module.mk	Sat Dec  9 23:55:36 2006
@@ -167,6 +167,7 @@
 		--with-ttf $$TTFINCDIR \
 		--with-afterbase=no \
 		--disable-glx \
+		--x-libraries=$(X11BASE)/lib --x-includes=$(X11BASE)/include \
 		$$MMX \
 		$(ASTEPDBG) \
 		--with-builtin-ungif \
