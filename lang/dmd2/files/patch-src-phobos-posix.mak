--- ../../src/phobos/posix.mak.orig	2014-04-13 22:44:09.100845919 -0700
+++ ../../src/phobos/posix.mak	2014-04-13 22:56:05.441324581 -0700
@@ -108,7 +108,7 @@
 	DMD = wine dmd.exe
 	RUN = wine
 else
-	DMD = ../dmd/src/dmd
+	DMD = ../../../dmd2/src/dmd/dmd
 	ifeq ($(OS),win32)
 		CC = dmc
 	else
