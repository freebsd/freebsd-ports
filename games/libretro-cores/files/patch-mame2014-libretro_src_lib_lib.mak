--- mame2014-libretro/src/lib/lib.mak.orig	2016-09-09 05:23:19 UTC
+++ mame2014-libretro/src/lib/lib.mak
@@ -595,9 +595,9 @@ SQLITE3_FLAGS += -fPIC
 endif
 endif
 
-ifeq ($(TARGETOS),linux)
-LIBS += -ldl
-endif
+#ifeq ($(TARGETOS),linux)
+#LIBS += -ldl
+#endif
 
 $(LIBOBJ)/sqlite3/sqlite3.o: $(3RDPARTY)/sqlite3/sqlite3.c | $(OSPREBUILD)
 	@echo Compiling $<...
