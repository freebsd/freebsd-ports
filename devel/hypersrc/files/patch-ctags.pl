--- ctags.pl.orig	Mon Apr  9 15:54:06 2001
+++ ctags.pl	Mon Apr  9 15:54:19 2001
@@ -23,7 +23,7 @@
 #
 $debug        = 0;
 $ctags        = "";					# DO NOT DEFAULT THIS AS "ctags" (might be GNU ctags)
-$ctags_args   = "-i +m -x -u";      # default ctags args
+$ctags_args   = "-x";      # default ctags args
 $enableNonTag = 0;
 
 #---------------------------------------------------------------------------
