--- cgx_1.1/src/smeUndo.cpp.orig	Thu Aug  7 15:41:36 2003
+++ cgx_1.1/src/smeUndo.cpp	Thu Aug  7 15:50:42 2003
@@ -23,7 +23,7 @@
 
 #include "smeUndo.h"
 
-#include <iostream.h>
+#include <iostream>
 
 bool smeUndoItemBase::isOwner ( const char* ownerString )
 {
