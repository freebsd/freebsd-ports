--- gdb/config/sparc/fbsd.mt.orig	Sat Jan  3 02:08:45 2004
+++ gdb/config/sparc/fbsd.mt	Sat Jan 24 20:10:22 2004
@@ -1,3 +1,4 @@
 # Target: FreeBSD/sparc64
 TDEPFILES= sparc-tdep.o sparc64-tdep.o sparc64fbsd-tdep.o corelow.o
+###TDEPFILES+= sparcnbsd-tdep.o nbsd-tdep.o solib.o solib-svr4.o solib-legacy.o
 TM_FILE= tm-fbsd.h
