--- deps/makefiles/build.mak.orig	2018-09-16 03:57:30 UTC
+++ deps/makefiles/build.mak
@@ -96,8 +96,8 @@ LDFLAGS   +=
 ifeq ($(RELEASE),on)
 # release variant
 CPPFLAGS += -DNDEBUG
-CFLAGS   += -O3
-CXXFLAGS += -O3
+# CFLAGS   += -O3
+# CXXFLAGS += -O3
 LDFLAGS  += -s
 else # RELEASE off
 ifeq ($(GPROF),on)
