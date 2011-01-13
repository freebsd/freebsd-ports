--- cnf/mak/afnix-freebsd.mak.orig	2011-01-13 18:27:28.000000000 +0100
+++ cnf/mak/afnix-freebsd.mak	2011-01-13 18:27:28.000000000 +0100
@@ -18,21 +18,21 @@
 # - compiler and linker section                                              -
 # ----------------------------------------------------------------------------
 
-CC              = g++
-LD              = gcc
-LK		= gcc
+CC              = $(CXX)
+LD              = $(CXX)
+LK		= $(CXX)
 AR              = ar
-STDCCFLAGS      = -Wall -Werror -MMD -fno-builtin
+STDCCFLAGS      = -Wall -W -MMD -fno-builtin
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
-STDDEFINES      = -D_REENTRANT
+STDDEFINES      = $(PTHREAD_CFLAGS)
 DBGDEFINES      = -DDEBUG
 OPTDEFINES      =
 STDINCLUDE      =
@@ -75,8 +75,8 @@ endif
 
 # adjust for freebsd platform
 ifeq ($(PLATNAME),freebsd)
-LD		= g++
-LK		= g++
+LD		= $(CXX)
+LK		= $(CXX)
 ARFLAGS		= rc
 LDFLAGS		= -shared
 AFXCPPLIBS	=
@@ -102,7 +102,7 @@ LKFLAGS		=
 
 # adjust linker flags for freebsd
 ifeq ($(PLATNAME),freebsd)
-LKFLAGS      	= -pthread
+LKFLAGS      	= $(PTHREAD_LIBS)
 endif
 
 # ----------------------------------------------------------------------------
