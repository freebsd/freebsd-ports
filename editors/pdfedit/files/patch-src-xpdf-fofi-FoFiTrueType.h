--- src/xpdf/fofi/FoFiTrueType.h.orig	2009-09-11 12:02:56 UTC
+++ src/xpdf/fofi/FoFiTrueType.h
@@ -156,7 +156,7 @@ private:
   Guint computeTableChecksum(Guchar *data, int length);
   void parse();
   void readPostTable();
-  int seekTable(char *tag);
+  int seekTable(const char *tag);
 
   TrueTypeTable *tables;
   int nTables;
