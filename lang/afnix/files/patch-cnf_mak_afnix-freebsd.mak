--- cnf/mak/afnix-freebsd.mak.orig	Sat Oct  7 20:11:57 2006
+++ cnf/mak/afnix-freebsd.mak	Sat Oct  7 20:14:17 2006
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
 STDCCFLAGS      = -Wall -Werror -MMD -fno-builtin
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
@@ -75,14 +75,11 @@
 
 # adjust for freebsd platform
 ifeq ($(PLATNAME),freebsd)
-LD		= g++
-LK		= g++
+LD		= $(CXX)
+LK		= $(CXX)
 ARFLAGS		= rc
 LDFLAGS		= -shared
 AFXCPPLIBS	=
-ifeq ($(LKMODE),soname)
-LDFLAGS	       += -Wl,-soname,$(SONAME)
-endif
 endif
 
 # ----------------------------------------------------------------------------
@@ -93,7 +90,7 @@
 
 # adjust linker flags for freebsd
 ifeq ($(PLATNAME),freebsd)
-LKFLAGS      	= -pthread
+LKFLAGS      	= $(PTHREAD_LIBS)
 endif
 
 # ----------------------------------------------------------------------------
