--- build/FreeBSD.inc.orig	2008-06-07 08:56:22.000000000 +0200
+++ build/FreeBSD.inc	2008-12-16 09:32:21.710673762 +0100
@@ -54,7 +54,7 @@
 MD?=mkdir -p
 NUL= /dev/null
 SLASH=/
-MAKE_VERSIONS=sh $(tbb_root)/build/version_info_linux.sh $(CPLUS) $(CPLUS_FLAGS) $(INCLUDES) >version_string.tmp
+MAKE_VERSIONS=sh $(tbb_root)/build/version_info_FreeBSD.sh $(CPLUS) $(CPLUS_FLAGS) $(INCLUDES) >version_string.tmp
 MAKE_TBBVARS=sh $(tbb_root)/build/generate_tbbvars.sh
 
 ifdef LD_LIBRARY_PATH
