--- Makefile.SH.orig	2012-12-19 12:25:23 UTC
+++ Makefile.SH
@@ -28,7 +28,6 @@ esac
 
 linklibperl='$(LIBPERL)'
 linklibperl_nonshr=''
-shrpldflags='$(LDDLFLAGS)'
 ldlibpth=''
 DPERL_EXTERNAL_GLOB='-DPERL_EXTERNAL_GLOB'
 DPERL_IS_MINIPERL='-DPERL_IS_MINIPERL'
