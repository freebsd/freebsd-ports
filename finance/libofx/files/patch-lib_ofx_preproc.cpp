--- lib/ofx_preproc.cpp.orig	Mon Feb 17 16:10:23 2003
+++ lib/ofx_preproc.cpp	Mon Feb 17 16:10:32 2003
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string>
+#include <unistd.h>
 #include "ParserEventGeneratorKit.h"
 #include "libofx.h"
 #include "messages.hh"
