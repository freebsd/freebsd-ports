--- src/highscore_tab.cc.orig	Sun Oct 30 00:49:30 2005
+++ src/highscore_tab.cc	Sun Oct 30 00:51:04 2005
@@ -16,7 +16,9 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
-#include <strstream.h>
+#include <sstream>
+#include <string>
+using namespace std;
 
 #include "highscore_tab.h"
 #include "intl.h"
@@ -37,11 +39,12 @@
    gtk_table_attach_defaults(GTK_TABLE(table), label, 2, 3, 0, 1);
 
    for (int i = 1; i <= 10; i++) {
-      char scratch[16];
-      std::ostrstream ost(scratch, sizeof(scratch));
-      
-      ost << i << std::ends;
-      GtkWidget* index_label = gtk_label_new(scratch);
+      ostringstream ost;
+      ost << i << ends;	// format string
+      string temp = ost.str();	// retrieve formatted string
+
+      GtkWidget* index_label = gtk_label_new(temp.c_str());
+
       gtk_table_attach_defaults(GTK_TABLE(table), index_label, 0, 1, i, i + 1);
 
       _names[i] = gtk_label_new(N_(""));
@@ -66,14 +69,12 @@
 HighScoreTab::Fill(const ScoreList& slist)
 {
    int index = 1;
-   for (std::list<Score>::const_iterator i = slist.Begin(); 
+   for (list<Score>::const_iterator i = slist.Begin(); 
 	i != slist.End(); i++) {
-      char scratch[16];
-      std::ostrstream ost(scratch, sizeof(scratch));
-      
-      ost << (*i).GetSeconds() << std::ends;
-
-      FillOneScore(index++, (*i).GetName().c_str(), scratch);
+	ostringstream ost;
+        ost << (*i).GetSeconds() << ends;	// format string
+	  string temp = ost.str();							// retrieve string
+	FillOneScore(index++, (*i).GetName().c_str(), temp.c_str());
    }
    
    for (; index <= 10; index++)
