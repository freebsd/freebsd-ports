$FreeBSD$

--- ../../hotspot1.3.1/build/linux/makefiles/gcc32.make	16 Sep 2002 06:21:28 -0000	1.1
+++ ../../hotspot1.3.1/build/linux/makefiles/gcc32.make	22 Nov 2004 17:19:42 -0000
@@ -108,8 +108,6 @@
 
 
 #####
-#harmless
-OPT_CFLAGS += -fmemoize-lookups
 #unneeded
 #OPT_CFLAGS += -fpeephole
 #bad
@@ -123,8 +121,8 @@
 # Set the environment variable HOTSPARC_HOTSPARC_GENERIC to "true"
 # to inhibit the effect of the previous line on CFLAGS.
 
-CPP = g++32
-CC  = gcc32
+CXX ?= g++32
+CC  ?= gcc32
 
 AOUT_FLAGS += -export-dynamic 
 DEBUG_CFLAGS += -g
