--- cnf/mak/afnix-gcc-3.mak.orig	Wed Jan 12 06:05:00 2005
+++ cnf/mak/afnix-gcc-3.mak	Wed Feb 16 19:18:04 2005
@@ -43,7 +43,7 @@
 # - compiler dependant libraries                                             -
 # ----------------------------------------------------------------------------
 
-AFXCPPLIBS	= -lsupc++
+AFXCPPLIBS	= -lstdc++
 
 # ----------------------------------------------------------------------------
 # - platform dependant linking flags                                         -
