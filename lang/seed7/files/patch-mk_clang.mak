--- mk_clang.mak.orig	2013-07-29 10:57:30.000000000 +0200
+++ mk_clang.mak	2013-07-29 10:58:03.000000000 +0200
@@ -10,7 +10,7 @@
 # CFLAGS = -O2 -g -Wall -Wextra -Wswitch-default -Wswitch-enum -Wcast-qual -Waggregate-return -Wwrite-strings -Wstrict-prototypes -Winline -Wconversion -Wshadow -Wpointer-arith -Wmissing-noreturn -Wno-multichar -Wc++-compat
 # CFLAGS = -O2 -g -x c++ -Wall -Wextra -Wswitch-default -Wswitch-enum -Wcast-qual -Waggregate-return -Wwrite-strings -Winline -Wconversion -Wshadow -Wpointer-arith -Wmissing-noreturn -Wno-multichar
 # CFLAGS = -O2 -fomit-frame-pointer -Wall -Wextra -Wswitch-default -Wcast-qual -Waggregate-return -Wwrite-strings -Winline -Wconversion -Wshadow -Wpointer-arith -Wmissing-noreturn -Wno-multichar
-CFLAGS = -O2 -g -Wall -Wstrict-prototypes -Winline -Wconversion -Wshadow -Wpointer-arith -ftrapv
+CFLAGS = -Wall -Wstrict-prototypes -Winline -Wconversion -Wshadow -Wpointer-arith -ftrapv -I%%LOCALBASE%%/include
 # CFLAGS = -O2 -g -x c++ -Wall -Winline -Wconversion -Wshadow -Wpointer-arith -ftrapv
 # CFLAGS = -O2 -g -Wall -Wstrict-prototypes -Winline -Wconversion -Wshadow -Wpointer-arith
 # CFLAGS = -O2 -g -Wall -Winline -Wconversion -Wshadow -Wpointer-arith
@@ -18,7 +18,7 @@
 # CFLAGS = -O2 -g -pg -Wall -Wstrict-prototypes -Winline -Wconversion -Wshadow -Wpointer-arith
 # CFLAGS = -O2 -fomit-frame-pointer -funroll-loops -Wall
 # CFLAGS = -O2 -funroll-loops -Wall -pg
-LDFLAGS =
+LDFLAGS = -L%%LOCALBASE%%/lib
 # LDFLAGS = -pg
 # LDFLAGS = -pg -lc_p
 SYSTEM_LIBS = -lm
@@ -37,7 +37,7 @@
 COMPILER_LIB = s7_comp.a
 ALL_S7_LIBS = ../bin/$(COMPILER_LIB) ../bin/$(COMP_DATA_LIB) ../bin/$(DRAW_LIB) ../bin/$(CONSOLE_LIB) ../bin/$(SEED7_LIB)
 # CC = g++
-CC = clang
+CC ?= clang
 GET_CC_VERSION_INFO = $(CC) --version >
 
 BIGINT_LIB_DEFINE = USE_BIG_RTL_LIBRARY
