--- Makefile.os~	Fri Jun 25 11:51:12 2004
+++ Makefile.os	Tue Jun 29 10:23:02 2004
@@ -23,8 +23,8 @@
 	DEPGEN_FLAGS ?= -MMD -MP
 	override CPPFLAGS += -DLINUX
 	ifeq ($(USE_UI_GTKMM), true)
-		INCLUDE_GTKMM ?= `pkg-config --cflags gtkmm-2.0`
-		LIBS_GTKMM ?= `pkg-config --libs gtkmm-2.0`
+		INCLUDE_GTKMM ?= `pkg-config --cflags gtkmm-2.4`
+		LIBS_GTKMM ?= `pkg-config --libs gtkmm-2.4`
 	endif
 endif
 
