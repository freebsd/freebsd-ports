--- src/plt/lib/cclk.cxx.orig	Fri Nov 29 13:10:11 2002
+++ src/plt/lib/cclk.cxx	Fri Nov 29 13:15:05 2002
@@ -53,7 +53,8 @@
   s_tinfo* c_getlocal (const long tclk) {
     // extract time info
     struct tm* tval;
-    if ((tval = localtime (&tclk)) == NULL) return 0;
+    time_t t = tclk;
+    if (t != tclk || (tval = localtime (&t)) == NULL) return 0;
     // fill in the data structure
     s_tinfo* tinfo = new s_tinfo;
     tinfo->d_secs = tval->tm_sec;
@@ -72,7 +73,8 @@
   s_tinfo* c_getutc (const long tclk) {
     // extract time info
     struct tm* tval;
-    if ((tval = gmtime (&tclk)) == NULL) return 0;
+    time_t t = tclk;
+    if (t != tclk || (tval = gmtime (&t)) == NULL) return 0;
     // fill in the data structure
     s_tinfo* tinfo = new s_tinfo;
     tinfo->d_secs = tval->tm_sec;
