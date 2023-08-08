Allow customisation of shrpldflags.

--- Makefile.SH.orig	2022-05-21 21:27:09 UTC
+++ Makefile.SH
@@ -40,7 +40,6 @@ linklibperl_nonshr=''
 pwd="`pwd`"
 linklibperl='$(LIBPERL)'
 linklibperl_nonshr=''
-shrpldflags='$(LDDLFLAGS)'
 ldlibpth=''
 DPERL_EXTERNAL_GLOB='-DPERL_EXTERNAL_GLOB'
 DPERL_IS_MINIPERL='-DPERL_IS_MINIPERL'
