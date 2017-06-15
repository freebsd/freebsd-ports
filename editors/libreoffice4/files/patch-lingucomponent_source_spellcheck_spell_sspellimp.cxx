Minimal exceprt from upstream fix only to unbreak build

https://cgit.freedesktop.org/libreoffice/core/commit/?id=072b32442e3f6f220936a93ad1fcbde57746b747

--- lingucomponent/source/spellcheck/spell/sspellimp.cxx.orig	2016-01-29 07:10:27 UTC
+++ lingucomponent/source/spellcheck/spell/sspellimp.cxx
@@ -37,7 +37,6 @@
 
 #include <lingutil.hxx>
 #include <hunspell.hxx>
-#include <dictmgr.hxx>
 #include <sspellimp.hxx>
 
 #include <linguistic/lngprops.hxx>
