--- ../svx/source/fmcomp/makefile.mk.orig	Sun May 19 14:22:34 2002
+++ ../svx/source/fmcomp/makefile.mk	Sun May 19 14:27:48 2002
@@ -74,6 +74,9 @@
 .INCLUDE :  sv.mk
 .INCLUDE :  $(PRJ)$/util$/makefile.pmk
 
+CFLAGS += -g
+CFLAGSCC += -g
+
 # --- Files --------------------------------------------------------
 
 CXXFILES= \
