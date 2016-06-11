--- src/xpdf/fofi/FoFiTrueType.h.orig	2016-06-11 10:41:33.311317000 +0900
+++ src/xpdf/fofi/FoFiTrueType.h	2016-06-11 10:41:43.645672000 +0900
@@ -156,7 +156,7 @@
   Guint computeTableChecksum(Guchar *data, int length);
   void parse();
   void readPostTable();
-  int seekTable(char *tag);
+  int seekTable(const char *tag);
 
   TrueTypeTable *tables;
   int nTables;
