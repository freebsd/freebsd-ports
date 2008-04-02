--- unzip-5.52.orig/consts.h
+++ consts.h
@@ -34,9 +34,9 @@
   "error:  expected central file header signature not found (file #%lu).\n";
 ZCONST char Far SeekMsg[] =
   "error [%s]:  attempt to seek before beginning of zipfile\n%s";
-ZCONST char Far FilenameNotMatched[] = "caution: filename not matched:  %s\n";
+ZCONST char Far FilenameNotMatched[] = "caution: filename not matched:  %.512s\n";
 ZCONST char Far ExclFilenameNotMatched[] =
-  "caution: excluded filename not matched:  %s\n";
+  "caution: excluded filename not matched:  %.512s\n";
 
 #ifdef VMS
   ZCONST char Far ReportMsg[] = "\
