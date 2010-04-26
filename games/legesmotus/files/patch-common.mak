--- common.mak.orig	2010-04-25 02:40:51.000000000 +0400
+++ common.mak	2010-04-25 23:05:50.000000000 +0400
@@ -8,7 +8,6 @@
 VERSION = 0.3.0
 
 # These may be overridden by config.mak
-DATADIR = data
 #UNIVERSAL = 1
 #UNIXSTYLE = 1
 
@@ -112,12 +111,6 @@
 CFLAGS += -Wall
 CXXFLAGS += -Wnon-virtual-dtor
 
-ifeq ($(DEBUG),1)
- CFLAGS += -g -O0
-else
- CFLAGS += -O2
-endif
-
 LDFLAGS += $(CFLAGS)
 CFLAGS += $(FLAGS_GL) $(INCLUDES)
 ifeq ($(MACHINE),Windows)
