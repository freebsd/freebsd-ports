--- src/plt/lib/cclk.cxx.orig	Wed Jan 12 06:05:00 2005
+++ src/plt/lib/cclk.cxx	Wed Feb 16 19:18:04 2005
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
