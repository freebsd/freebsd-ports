--- gbtools/src/blatSrc/lib/gff3.c.orig	2016-11-10 21:14:27 UTC
+++ gbtools/src/blatSrc/lib/gff3.c
@@ -7,6 +7,7 @@
 /* Copyright (C) 2014 The Regents of the University of California 
  * See README in this or parent directory for licensing information. */
 #include "common.h"
+#include "dnaseq.h"
 #include "gff3.h"
 #include <limits.h>
 #include "errAbort.h"
