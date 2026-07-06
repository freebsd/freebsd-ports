Allow customisation of shrpldflags.

--- Makefile.SH.orig	2022-06-19 19:29:35 UTC
+++ Makefile.SH
@@ -40,7 +40,6 @@ linklibperl_nonshr=''
 pwd="`pwd`"
 linklibperl='$(LIBPERL)'
 linklibperl_nonshr=''
-shrpldflags='$(LDDLFLAGS)'
 ldlibpth=''
 DPERL_EXTERNAL_GLOB='-DPERL_EXTERNAL_GLOB'
 DPERL_IS_MINIPERL='-DPERL_IS_MINIPERL'
