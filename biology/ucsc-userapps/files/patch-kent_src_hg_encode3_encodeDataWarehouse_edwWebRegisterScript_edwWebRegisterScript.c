--- kent/src/hg/encode3/encodeDataWarehouse/edwWebRegisterScript/edwWebRegisterScript.c.orig	2021-04-14 11:23:12 UTC
+++ kent/src/hg/encode3/encodeDataWarehouse/edwWebRegisterScript/edwWebRegisterScript.c
@@ -2,7 +2,7 @@
 
 /* Copyright (C) 2014 The Regents of the University of California 
  * See README in this or parent directory for licensing information. */
-#include <uuid/uuid.h>
+#include <uuid.h>
 #include "common.h"
 #include "linefile.h"
 #include "hash.h"
