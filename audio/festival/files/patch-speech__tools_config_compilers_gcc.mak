--- speech_tools/config/compilers/gcc.mak.orig	2001-04-04 11:55:32 UTC
+++ speech_tools/config/compilers/gcc.mak
@@ -38,8 +38,4 @@
  ##                                                                       ##
  ###########################################################################
 
-ifdef GCC
-include $(EST)/config/compilers/$(GCC).mak
-else
 include $(EST)/config/compilers/gcc_defaults.mak
-endif
