--- cnf/mak/afnix-freebsd.mak.orig	Wed Aug 31 21:59:00 2005
+++ cnf/mak/afnix-freebsd.mak	Wed Aug 31 22:00:29 2005
@@ -1,6 +1,6 @@
 # ----------------------------------------------------------------------------
-# - afnix-gcc-3                                                              -
-# - afnix compiler configuration - gcc configuration                         -
+# - afnix-freebsd                                                            -
+# - afnix compiler configuration - FreeBSD system compiler configuration     -
 # ----------------------------------------------------------------------------
 # - This program is  free software;  you can  redistribute it and/or  modify -
 # - it provided that this copyright notice is kept intact.                   -
@@ -18,21 +18,21 @@
 # - compiler and linker section                                              -
 # ----------------------------------------------------------------------------
 
-CC              = g++
-LD              = gcc
-LK		= gcc
+CC              = $(CXX)
+LD              = $(CXX)
+LK		= $(CXX)
 AR              = ar rc
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
@@ -68,8 +68,8 @@
 
 # adjust for freebsd platform
 ifeq ($(PLATNAME),freebsd)
-LD		= g++
-LK		= g++
+LD		= $(CXX)
+LK		= $(CXX)
 LDFLAGS		= -shared
 AFXCPPLIBS	=
 ifeq ($(LKMODE),soname)
@@ -85,7 +85,7 @@
 
 # adjust linker flags for freebsd
 ifeq ($(PLATNAME),freebsd)
-LKFLAGS      	= -pthread
+LKFLAGS      	= $(PTHREAD_LIBS)
 endif
 
 # ----------------------------------------------------------------------------
@@ -102,13 +102,10 @@
 
 # adjust intel processor
 ifeq ($(PROCNAME)-$(PROCTYPE),ia-586)
-PLTCCFLAGS     += -mcpu=i586
 endif
 ifeq ($(PROCNAME)-$(PROCTYPE),ia-686)
-PLTCCFLAGS     += -mcpu=i686
 endif
 
 # adjust sparc processor
 ifeq ($(PROCNAME)-$(PROCTYPE),sparc-ultra)
-PLTCCFLAGS     += -mcpu=ultrasparc -mtune=ultrasparc
 endif
