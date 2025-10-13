--- build/make/zldefs.make.orig	2025-10-08 08:51:15 UTC
+++ build/make/zldefs.make
@@ -21,8 +21,8 @@ CPPFLAGS += -I. -Iinclude -Isrc -Icpp/include -Icpp/sr
 
 # base compilation flags
 CPPFLAGS += -I. -Iinclude -Isrc -Icpp/include -Icpp/src
-CFLAGS   += -O1 -std=c11  # code must be compliant with C11
-CXXFLAGS += -O1 -std=c++1z  # for gtests
+CFLAGS   += -std=c11  # code must be compliant with C11
+CXXFLAGS += -std=c++1z  # for gtests
 DEBUGFLAGS ?= -g \
 	-Wall -Wcast-qual -Wcast-align -Wshadow \
 	-Wstrict-aliasing=1 -Wundef -Wpointer-arith -Wvla -Wformat=2 \
