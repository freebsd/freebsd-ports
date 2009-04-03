--- src/orsa/xorsa.h.orig	2004-07-13 11:21:19.000000000 +0900
+++ src/orsa/xorsa.h	2009-04-02 13:48:37.000000000 +0900
@@ -62,7 +62,7 @@
   ObjectItem(QListView *parent, QString label1, QString label2 = QString::null, QString label3 = QString::null, QString label4 = QString::null, QString label5 = QString::null, QString label6 = QString::null, QString label7 = QString::null, QString label8 = QString::null);
   
  public:
-  int ObjectItem::compare(QListViewItem * i, int col, bool ascending) const;    
+  int compare(QListViewItem * i, int col, bool ascending) const;    
   
 };
 
