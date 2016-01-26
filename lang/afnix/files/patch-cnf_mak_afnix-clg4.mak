--- cnf/mak/afnix-clg4.mak.orig	2015-01-03 13:34:32 UTC
+++ cnf/mak/afnix-clg4.mak
@@ -19,19 +19,19 @@
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
-STDCCFLAGS      = -std=c++11 -Wall -Werror -Wno-overloaded-virtual
+STDCCFLAGS      = -std=c++11 -Wall -W -Wno-overloaded-virtual
 STDCCFLAGS     += -fno-builtin -Qunused-arguments
 STACCFLAGS	=
 DYNCCFLAGS	= -fPIC
 PLTCCFLAGS      = 
 DEBUGFLAGS      = -g
-OPTCCFLAGS      = -O2
+OPTCCFLAGS      =
 PFLCCFLAGS      =
 COVCCFLAGS      =
 CPPCCFLAGS      = -nostdinc -nostdinc++
