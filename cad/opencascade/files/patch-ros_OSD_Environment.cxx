--- ros/src/OSD/OSD_Environment.cxx.orig	Wed Mar 21 22:12:48 2007
+++ ros/src/OSD/OSD_Environment.cxx	Thu Dec 13 21:25:36 2007
@@ -1,18 +1,18 @@
 
 #ifndef WNT
 
+#include <stdlib.h>
+#include <stdio.h>
+#include <string.h>
+
+#include <errno.h>
+
 #include <Standard_NullObject.hxx>
 #include <Standard_ConstructionError.hxx>
 #include <Standard_Failure.hxx>
 #include <Standard_Mutex.hxx>
 #include <OSD_Environment.ixx>
 #include <OSD_WhoAmI.hxx>
-
-#include <stdlib.h>
-#include <stdio.h>
-#include <string.h>
-
-#include <errno.h>
 
 static const OSD_WhoAmI Iam = OSD_WEnvironment;
 
