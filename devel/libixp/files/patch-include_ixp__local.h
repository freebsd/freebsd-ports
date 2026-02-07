--- include/ixp_local.h.orig	2008-09-21 03:39:51 UTC
+++ include/ixp_local.h
@@ -2,7 +2,7 @@
 #define IXP_P9_STRUCTS
 #include <ixp.h>
 
-char *argv0;
+extern char *argv0;
 #define ARGBEGIN \
 		int _argtmp=0, _inargv=0; char *_argv=nil; \
 		if(!argv0) {argv0=*argv; argv++, argc--;} \
