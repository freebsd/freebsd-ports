--- sc/source/ui/docshell/datastream.cxx.orig	2017-10-25 14:25:39 UTC
+++ sc/source/ui/docshell/datastream.cxx
@@ -84,7 +84,7 @@ class CSVHandler (public)
     static void begin_row() {}
     static void end_row() {}
 
-    void cell(const char* p, size_t n)
+    void cell(const char* p, size_t n, bool /*transient*/)
     {
         if (mnCols >= mnColCount)
             return;
