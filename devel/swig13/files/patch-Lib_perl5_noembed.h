--- Lib/perl5/noembed.h.orig	2009-08-17 12:06:08 UTC
+++ Lib/perl5/noembed.h
@@ -65,7 +65,9 @@
   #undef eof
 #endif
 #ifdef bool
-  #undef bool
+  #ifndef __bool_true_false_are_defined
+    #undef bool
+  #endif
 #endif
 #ifdef close
   #undef close
