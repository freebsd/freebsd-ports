$FreeBSD$

--- ../../hotspot1.3.1/build/linux/makefiles/gcc.make	23 Apr 2003 18:04:37 -0000	1.6
+++ ../../hotspot1.3.1/build/linux/makefiles/gcc.make	22 Nov 2004 17:19:42 -0000
@@ -36,8 +36,6 @@
 
 
 #####
-#harmless
-OPT_CFLAGS += -fmemoize-lookups
 #unneeded
 #OPT_CFLAGS += -fpeephole
 #bad
@@ -51,8 +49,8 @@
 # Set the environment variable HOTSPARC_HOTSPARC_GENERIC to "true"
 # to inhibit the effect of the previous line on CFLAGS.
 
-CPP = g++
-CC  = gcc
+CXX ?= g++
+CC  ?= gcc
 
 AOUT_FLAGS += -export-dynamic 
 DEBUG_CFLAGS += -g
