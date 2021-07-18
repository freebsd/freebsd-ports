--- kent/src/hg/encode3/eap/eapFinish/eapFinish.c.orig	2021-04-14 11:23:30 UTC
+++ kent/src/hg/encode3/eap/eapFinish/eapFinish.c
@@ -3,7 +3,7 @@
 
 /* Copyright (C) 2014 The Regents of the University of California 
  * See README in this or parent directory for licensing information. */
-#include <uuid/uuid.h>
+#include <uuid.h>
 #include "common.h"
 #include "linefile.h"
 #include "hash.h"
