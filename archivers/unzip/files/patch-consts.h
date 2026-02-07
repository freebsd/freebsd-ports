--- consts.h.orig	2002-03-23 15:52:48 UTC
+++ consts.h
@@ -34,9 +34,9 @@ ZCONST char Far CentSigMsg[] =
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
