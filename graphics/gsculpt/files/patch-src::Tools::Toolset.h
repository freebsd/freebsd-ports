--- ./src/Tools/Toolset.h.orig	Mon Jul 21 16:35:45 2003
+++ ./src/Tools/Toolset.h	Mon Jul 21 16:36:04 2003
@@ -18,7 +18,8 @@
 #include "CadView.h"
 #include "Toolbox.h"
 
-
+using std::string;
+using std::vector;
 
 class Toolset
 {
