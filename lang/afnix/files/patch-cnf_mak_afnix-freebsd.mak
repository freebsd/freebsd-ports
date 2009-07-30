--- cnf/mak/afnix-freebsd.mak.orig	2009-07-30 15:29:26.000000000 +0200
+++ cnf/mak/afnix-freebsd.mak	2009-07-30 15:30:41.000000000 +0200
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
@@ -75,14 +75,11 @@ endif
 
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
-LDFLAGS	       += -Wl,-soname,$(SOMIN)
-endif
 endif
 
 # adjust for gnu/freebsd platform
@@ -102,7 +99,7 @@ LKFLAGS		=
 
 # adjust linker flags for freebsd
 ifeq ($(PLATNAME),freebsd)
-LKFLAGS      	= -pthread
+LKFLAGS      	= $(PTHREAD_LIBS)
 endif
 
 # ----------------------------------------------------------------------------
