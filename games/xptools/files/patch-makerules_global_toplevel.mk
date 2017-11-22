--- makerules/global/toplevel.mk.orig	2017-04-14 14:21:02 UTC
+++ makerules/global/toplevel.mk
@@ -8,7 +8,7 @@
 .PHONY: all clean linkclean
 
 PLATFORM	:= $(shell uname)
-ARCHITECTURE	:= $(shell uname -m)
+ARCHITECTURE	:= $(shell uname -m |sed s/amd64/x86_64/)
 WD		:= $(PWD)
 
 
@@ -23,6 +23,9 @@
 ifeq ($(PLATFORM), Linux)
 	PLAT_LINUX	:= Yes
 endif
+ifeq ($(PLATFORM), FreeBSD)
+	PLAT_LINUX	:= Yes
+endif
 ifeq ($(PLATFORM), Darwin)
 	PLAT_DARWIN	:= Yes
 endif
@@ -110,9 +113,9 @@
 # if someone has a ppc linux machine, please define -DLIL/-DBIG in the code,
 # remove them here and use the __ppc__ macro to resolve endianess issues
 	DEFINES		:= -DLIN=1 -DIBM=0 -DAPL=0 -DLIL=1 -DBIG=0
-	CFLAGS		:= $(M32_SWITCH) -Wno-deprecated-declarations -Wno-multichar -pipe -frounding-math
-	CXXFLAGS	:= $(M32_SWITCH) -Wno-deprecated -Wno-deprecated-declarations -Wno-multichar -pipe -frounding-math
-	LDFLAGS		:= $(M32_SWITCH) -static-libgcc
+	CFLAGS		:= $(M32_SWITCH) -Wno-deprecated-declarations -Wno-multichar -pipe
+	CXXFLAGS	:= $(M32_SWITCH) -Wno-deprecated -Wno-deprecated-declarations -Wno-multichar -pipe
+	LDFLAGS		:= $(M32_SWITCH)
 	BARE_LDFLAGS	:=
 	STRIPFLAGS	:= -s -x
 endif
