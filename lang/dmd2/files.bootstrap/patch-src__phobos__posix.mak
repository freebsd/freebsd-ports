--- ../../src/phobos/posix.mak.orig	2016-04-08 22:04:38.300872000 -0700
+++ ../../src/phobos/posix.mak	2016-04-08 22:11:33.637271000 -0700
@@ -121,7 +121,7 @@
 	DMD = wine dmd.exe
 	RUN = wine
 else
-	DMD = ../dmd/src/dmd
+	DMD = ../dmd/dmd
 	ifeq ($(OS),win32)
 		CC = dmc
 	else
