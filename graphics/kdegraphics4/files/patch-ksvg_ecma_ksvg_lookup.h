===================================================================
RCS file: /usr/repos/kde/kdegraphics/ksvg/ecma/ksvg_lookup.h,v
retrieving revision 1.41
retrieving revision 1.41.2.2
diff -u -p -r1.41 -r1.41.2.2
--- ksvg/ecma/ksvg_lookup.h	2003/08/17 11:49:23	1.41
+++ ksvg/ecma/ksvg_lookup.h	2004/06/07 07:45:09	1.41.2.2
@@ -24,8 +24,7 @@
 #include <kjs/object.h>
 #include <kjs/lookup.h>
 #include <kjs/interpreter.h> // for ExecState
-
-class KSVGScriptInterpreter;
+#include "ksvg_scriptinterpreter.h"
 
 #define KSVG_GET_COMMON \
 public: \
