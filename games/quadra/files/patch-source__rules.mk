--- source/rules.mk.orig	2008-12-20 08:14:57.000000000 +0100
+++ source/rules.mk	2012-02-19 18:04:11.000000000 +0100
@@ -18,7 +18,9 @@
 #
 # $Id: rules.mk 684 2008-12-20 07:14:57Z pphaneuf $
 
-source/quadra: LDLIBS+=$(SDL_LIBS) -lpng -lz
+EXT_LIBS := -lcompat  # needed in FBSD for the ftime function
+
+source/quadra: LDLIBS+=$(SDL_LIBS) -lpng -lz $(EXT_LIBS)
 source/quadra: $(QUADRA_OBJECTS) $(SDL_MAIN_OBJ) skelton/lib/libugs_s.a
 
 quadra.res: $(shell cat resources.txt) resources.txt skelton/tools/wadder/wadder
