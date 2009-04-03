--- src/libxorsa/xorsa_import_astorb_objects.h.orig	2005-01-05 12:04:17.000000000 +0900
+++ src/libxorsa/xorsa_import_astorb_objects.h	2009-04-02 13:48:37.000000000 +0900
@@ -600,7 +600,7 @@
   inline XOrsaAstorbObjectItem(QListView *parent, QString label1, QString label2 = QString::null, QString label3 = QString::null, QString label4 = QString::null, QString label5 = QString::null, QString label6 = QString::null, QString label7 = QString::null, QString label8 = QString::null) : QListViewItem(parent, label1, label2, label3, label4, label5, label6, label7, label8) { };
   
  public:
-  inline int XOrsaAstorbObjectItem::compare(QListViewItem *i, int col, bool ascending) const {
+  inline int compare(QListViewItem *i, int col, bool ascending) const {
 
     using std::atof;
         
