--- src/kbitem.cpp.orig	Fri Apr 16 12:04:47 2004
+++ src/kbitem.cpp	Fri Apr 16 12:05:13 2004
@@ -23,12 +23,12 @@
 
 int kbitem::compare(QListViewItem * i, int col, bool ascending) const
 {
-	if ((this->rtti() == 1001) and (i->rtti() == 1002)) 
+	if ((this->rtti() == 1001) && (i->rtti() == 1002)) 
 	{
 		if (ascending) return -1;
 		else return 1;
 	}
-	else if ((this->rtti() == 1002) and (i->rtti() == 1001)) 
+	else if ((this->rtti() == 1002) && (i->rtti() == 1001)) 
 	{
 		if (ascending) return 1;
 		else return -1; 
