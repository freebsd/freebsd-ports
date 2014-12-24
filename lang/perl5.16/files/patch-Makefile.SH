--- Makefile.SH.orig	2013-03-04 15:16:21 UTC
+++ Makefile.SH
@@ -28,7 +28,6 @@ esac
 
 linklibperl='$(LIBPERL)'
 linklibperl_nonshr=''
-shrpldflags='$(LDDLFLAGS)'
 ldlibpth=''
 DPERL_EXTERNAL_GLOB='-DPERL_EXTERNAL_GLOB'
 DPERL_IS_MINIPERL='-DPERL_IS_MINIPERL'
