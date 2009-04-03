--- src/libxorsa/xorsa_analysis.h.orig	2004-06-25 09:58:30.000000000 +0900
+++ src/libxorsa/xorsa_analysis.h	2009-04-02 13:48:37.000000000 +0900
@@ -129,7 +129,7 @@
   XOrsaPeaksListItem(QListView *parent, QString label1, QString label2 = QString::null, QString label3 = QString::null, QString label4 = QString::null, QString label5 = QString::null, QString label6 = QString::null, QString label7 = QString::null, QString label8 = QString::null);
   
  public:
-  int XOrsaPeaksListItem::compare(QListViewItem * i, int col, bool ascending) const;    
+  int compare(QListViewItem * i, int col, bool ascending) const;    
   
 };
 
