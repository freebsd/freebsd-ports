--- src/mainwidget.cpp.orig	Fri Mar  4 09:38:35 2005
+++ src/mainwidget.cpp	Fri Mar  4 11:49:53 2005
@@ -18,6 +18,7 @@
  *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
  ***************************************************************************/
 
+#include <config.h>
 
 #include "mainwidget.h"
 #include "options.h"
@@ -44,6 +45,10 @@
 #include <kpushbutton.h>
 #include <kmessagebox.h>
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 #include <fstream>
 using namespace std;
 
@@ -1016,7 +1021,7 @@
 }
 
 void MainWidget::marginValueChanged( double newValue)  {
-	if (marginValueSynconizingNecessary and checkBoxSyncronizeMargins->isChecked()) {
+	if (marginValueSynconizingNecessary && checkBoxSyncronizeMargins->isChecked()) {
 		marginValueSynconizingNecessary=false;
 		marginsL->setValue(newValue);
 		marginsR->setValue(newValue);
