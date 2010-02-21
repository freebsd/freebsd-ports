
$FreeBSD$

--- src/uicommon/nmv-terminal.cc.orig
+++ src/uicommon/nmv-terminal.cc
@@ -44,7 +44,6 @@
 #include <vte/vte.h>
 #include "common/nmv-exception.h"
 #include "common/nmv-log-stream-utils.h"
-#include <utmp.h>
 
 NEMIVER_BEGIN_NAMESPACE(nemiver)
 
