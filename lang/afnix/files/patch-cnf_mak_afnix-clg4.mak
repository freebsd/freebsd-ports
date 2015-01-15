--- cnf/mak/afnix-clg4.mak.orig	2015-01-09 13:27:16.000000000 +0100
+++ cnf/mak/afnix-clg4.mak	2015-01-09 13:28:08.000000000 +0100
@@ -19,23 +19,23 @@
 # - compiler and linker section                                              -
 # ----------------------------------------------------------------------------
 
-CC              = clang++
-LD              = clang++
-LK		= clang++
+CC              = $(CXX)
+LD              = $(CXX)
+LK		= $(CXX)
 AR              = ar
 RANLIB		= ranlib
 STDEVFLAGS      =
-STDCCFLAGS      = -std=c++11 -Wall -Werror -Wno-overloaded-virtual -fno-builtin
+STDCCFLAGS      = -std=c++11 -Wall -W -Wno-overloaded-virtual -fno-builtin
 STACCFLAGS	=
 DYNCCFLAGS	= -fPIC
 PLTCCFLAGS      = 
 DEBUGFLAGS      = -g
-OPTCCFLAGS      = -O2
+OPTCCFLAGS      =
 PFLCCFLAGS      =
 COVCCFLAGS      =
 CPPCCFLAGS      = -nostdinc -nostdinc++
 CXXCCFLAGS      = 
-STDDEFINES      =
+STDDEFINES      = $(PTHREAD_CFLAGS)
 DBGDEFINES      = -DAFNIX_DEBUG
 OPTDEFINES      =
 PFLDEFINES	=
