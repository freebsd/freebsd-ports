--- src/epos.h.orig	2005-04-15 00:26:11 UTC
+++ src/epos.h
@@ -43,6 +43,7 @@
 		#include <rx.h>
 	#else
 	    #ifdef HAVE_REGEX_H
+		#include <sys/types.h>
 		#include <regex.h>
 	    #else
 		#include "rx.h"
