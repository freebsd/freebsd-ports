--- ./fam/FileSystem.c++.orig	2003-04-15 06:21:30.000000000 +0200
+++ ./fam/FileSystem.c++	2014-01-03 02:35:10.000000000 +0100
@@ -22,7 +22,7 @@
 
 #include "FileSystem.h"
 
-#include <mntent.h>
+#include "mntent.h"
 #include <string.h>
 
 #include "Event.h"
