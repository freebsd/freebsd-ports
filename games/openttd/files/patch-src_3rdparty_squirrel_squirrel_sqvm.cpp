--- src/3rdparty/squirrel/squirrel/sqvm.cpp.orig	2017-06-13 18:34:58 UTC
+++ src/3rdparty/squirrel/squirrel/sqvm.cpp
@@ -4,9 +4,9 @@
 
 #include "../../../stdafx.h"
 
+#include <math.h>
 #include <squirrel.h>
 #include "sqpcheader.h"
-#include <math.h>
 #include "sqopcodes.h"
 #include "sqfuncproto.h"
 #include "sqvm.h"
