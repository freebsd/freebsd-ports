--- cnf/mak/afnix-gcc-3.mak.orig	Wed Jan 12 06:05:00 2005
+++ cnf/mak/afnix-gcc-3.mak	Wed Feb 16 19:18:04 2005
@@ -22,7 +22,7 @@
 LD              = gcc
 LK		= gcc
 AR              = ar rc
-STDCCFLAGS      = -Wall -Werror -MMD -fno-builtin
+STDCCFLAGS      = -Wall -MMD -fno-builtin
 STACCFLAGS	=
 DYNCCFLAGS	= -fPIC
 PLTCCFLAGS      =
@@ -43,7 +43,7 @@
 # - compiler dependant libraries                                             -
 # ----------------------------------------------------------------------------
 
-AFXCPPLIBS	= -lsupc++
+AFXCPPLIBS	= -lstdc++
 
 # ----------------------------------------------------------------------------
 # - platform dependant linking flags                                         -
