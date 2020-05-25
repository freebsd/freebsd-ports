--- example/.cscout/host-incs.h.orig	2019-12-02 21:11:13 UTC
+++ example/.cscout/host-incs.h
@@ -8,6 +8,6 @@
  */
 
 
-#pragma includepath "../../include/stdc"
+#pragma includepath "/usr/local/include/cscout/stdc"
 /* To avoid unused include file warnings */
 static void _cscout_dummy2(void) { _cscout_dummy2(); }
