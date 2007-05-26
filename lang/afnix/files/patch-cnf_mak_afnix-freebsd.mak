--- cnf/mak/afnix-freebsd.mak.orig	Sat May 26 23:59:55 2007
+++ cnf/mak/afnix-freebsd.mak	Sun May 27 00:00:45 2007
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
 
 # adjust for gnu/freebsd platform
@@ -102,7 +99,7 @@
 
 # adjust linker flags for freebsd
 ifeq ($(PLATNAME),freebsd)
-LKFLAGS      	= -pthread
+LKFLAGS      	= $(PTHREAD_LIBS)
 endif
 
 # ----------------------------------------------------------------------------
