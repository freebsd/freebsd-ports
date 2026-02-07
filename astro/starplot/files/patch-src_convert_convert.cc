--- src/convert/convert.cc.orig	2008-04-14 18:19:13 UTC
+++ src/convert/convert.cc
@@ -64,7 +64,7 @@ available on the StarPlot web page, you 
 in that package for more information.") << endl << endl;
 
   do {
-    moredata = infile.getline(record, 999, '\n');
+    moredata = (bool)infile.getline(record, 999, '\n');
     record[999] = 0;
 
     // $ ; and , have special meanings to StarPlot, so purge them:
