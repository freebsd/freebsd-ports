--- autoexec.c.orig	2015-03-23 11:03:05 UTC
+++ autoexec.c
@@ -2,12 +2,17 @@
 /* this file is in the public domain */
 /* Author: Vincent Labrecque <vincent@openbsd.org>	April 2002 */
 
+#include <sys/param.h>
 #include <sys/queue.h>
 #include <fnmatch.h>
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#ifndef __OpenBSD__
+#include <stdlib.h>
+#include <malloc_np.h>
+#endif
 
 #include "def.h"
 #include "funmap.h"
@@ -44,8 +49,13 @@ find_autoexec(const char *fname)
 	SLIST_FOREACH(ae, &autos, next) {
 		if (fnmatch(ae->pattern, fname, 0) == 0) {
 			if (used >= have) {
+				#if defined(__OpenBSD__)
 				npfl = reallocarray(pfl, have + AUTO_GROW + 1,
 				    sizeof(PF));
+				#else
+				npfl = realloc(pfl, (have + AUTO_GROW + 1) *
+				    sizeof(PF));
+				#endif
 				if (npfl == NULL)
 					panic("out of memory");
 				pfl = npfl;
