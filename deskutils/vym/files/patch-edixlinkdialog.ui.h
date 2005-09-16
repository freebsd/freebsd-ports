--- editxlinkdialog.ui.h.orig	Wed May 18 09:39:51 2005
+++ editxlinkdialog.ui.h	Fri Sep 16 22:24:33 2005
@@ -6,6 +6,8 @@
 ** init() function in place of a constructor, and a destroy() function in
 ** place of a destructor.
 *****************************************************************************/
+#include <typeinfo>
+
 void EditXLinkDialog::init()
 {
 	delink=false;
