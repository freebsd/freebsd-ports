--- clanbomber/Config.cpp.orig	Fri Nov  4 12:40:51 2005
+++ clanbomber/Config.cpp	Fri Nov  4 12:48:30 2005
@@ -16,15 +16,15 @@
  ***************************************************************************/
 // $Id: Config.cpp,v 1.5 2004/01/13 12:34:48 xmassx Exp $
 
+#include <fstream>
+#include <cstdio>
+
 #include <ClanLib/Display/Input/input.h>
 
 #include "ClanBomber.h"
 #include "Config.h"
 
 #include "Controller.h"
-
-#include <fstream>
-#include <cstdio>
 
 CL_String Config::filename	= "clanbomber.cfg";
 
