--- kent/src/hg/encode3/encodeDataWarehouse/edwWebRegisterScript/edwWebRegisterScript.c.orig	2024-10-16 04:15:27 UTC
+++ kent/src/hg/encode3/encodeDataWarehouse/edwWebRegisterScript/edwWebRegisterScript.c
@@ -2,7 +2,7 @@
 
 /* Copyright (C) 2014 The Regents of the University of California 
  * See kent/LICENSE or http://genome.ucsc.edu/license/ for licensing information. */
-#include <uuid/uuid.h>
+#include <uuid.h>
 #include "common.h"
 #include "linefile.h"
 #include "hash.h"
