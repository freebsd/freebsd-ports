--- src/libxorsa/xorsa_object_selector.cc.orig	2004-06-25 12:12:57.000000000 +0900
+++ src/libxorsa/xorsa_object_selector.cc	2009-04-02 13:48:37.000000000 +0900
@@ -40,7 +40,7 @@
   XOrsaObjectItem(QListView *parent, QString label1, QString label2 = QString::null, QString label3 = QString::null, QString label4 = QString::null, QString label5 = QString::null, QString label6 = QString::null, QString label7 = QString::null, QString label8 = QString::null);
   
  public:
-  int XOrsaObjectItem::compare(QListViewItem * i, int col, bool ascending) const;    
+  int compare(QListViewItem * i, int col, bool ascending) const;    
   
 };
 
