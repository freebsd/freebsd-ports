--- src/SUIT/SUIT_ResourceMgr.cxx.orig	2009-05-27 16:00:05.000000000 +0700
+++ src/SUIT/SUIT_ResourceMgr.cxx	2009-05-27 16:01:20.000000000 +0700
@@ -20,6 +20,8 @@
 //  See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
 //
 #include "SUIT_ResourceMgr.h"
+#include <cstdlib>
+#include <climits>
 
 #include <qfileinfo.h>
 #include <qdir.h>
