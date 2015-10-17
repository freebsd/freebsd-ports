--- common.mk.orig	2010-09-03 19:22:37 UTC
+++ common.mk
@@ -9,7 +9,6 @@ FRAMEWORKS = /Library/Frameworks
 VERSION = 0.4.0
 
 # These may be overridden by config.mk
-DATADIR = data
 #UNIVERSAL = 1
 #NOBUNDLE = 1
 
@@ -174,12 +173,10 @@ CXXFLAGS += -Wnon-virtual-dtor
 
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
 
