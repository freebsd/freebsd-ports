--- cnf/mak/afnix-freebsd.mak.orig	2013-05-04 18:23:18.000000000 +0200
+++ cnf/mak/afnix-freebsd.mak	2013-05-04 18:26:47.000000000 +0200
@@ -19,23 +19,23 @@
 # - compiler and linker section                                              -
 # ----------------------------------------------------------------------------
 
-CC              = g++
-LD              = g++
-LK		= g++
+CC              = $(CXX)
+LD              = $(CXX)
+LK		= $(CXX)
 AR              = ar
 RANLIB		= ranlib
 STDEVFLAGS      =
-STDCCFLAGS      = -Wall -Werror -fno-builtin
+STDCCFLAGS      = -Wall -W -fno-builtin
 STACCFLAGS	=
 DYNCCFLAGS	= -fPIC
 PLTCCFLAGS      = 
 DEBUGFLAGS      = -g
-OPTCCFLAGS      = -O2
+OPTCCFLAGS      =
 PFLCCFLAGS      = -g -pg
 COVCCFLAGS      = -g -fprofile-arcs -ftest-coverage
 CPPCCFLAGS      = -nostdinc -nostdinc++
 CXXCCFLAGS      = 
-STDDEFINES      =
+STDDEFINES      = $(PTHREAD_CFLAGS)
 DBGDEFINES      = -DAFNIX_DEBUG
 OPTDEFINES      =
 PFLDEFINES	= -DAFNIX_DEBUG -DAFNIX_PROFILED
