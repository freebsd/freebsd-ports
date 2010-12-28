--- common.mk.orig	2010-09-03 23:22:37.000000000 +0400
+++ common.mk	2010-12-27 02:20:26.000000000 +0300
@@ -9,7 +9,6 @@
 VERSION = 0.4.0
 
 # These may be overridden by config.mk
-DATADIR = data
 #UNIVERSAL = 1
 #NOBUNDLE = 1
 
@@ -174,12 +173,10 @@
 
 ifeq ($(DEBUG),1)
  RELEASE = debug
- CFLAGS += -g -O0 -DLM_DEBUG
 else
  RELEASE = release
  # Take O-flag from CFLAGS if we already have it set
  ifneq ($(filter -O%,$(CFLAGS)),)
-  CFLAGS += -O2
  endif
 endif
 
