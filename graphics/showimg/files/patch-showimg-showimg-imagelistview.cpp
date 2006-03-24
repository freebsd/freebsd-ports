--- showimg/showimg/imagelistview.cpp.orig	Sat Jan 28 23:00:28 2006
+++ showimg/showimg/imagelistview.cpp	Sat Jan 28 23:01:24 2006
@@ -28,6 +28,8 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <stdlib.h>
+
 #include "imagelistview.h"
 
 // Local
@@ -542,7 +542,9 @@
 	////////
 	m_popup->insertSeparator();
 	aImageInfo->plug(m_popup);
+#ifdef WANT_LIBKEXIDB
 	if(mw->getCategoryDBManager()->isConnected()) aCategoryProperties->plug(m_popup);
+#endif
 	aFileProperties->plug(m_popup);
 }
 
