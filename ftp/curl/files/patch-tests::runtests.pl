--- tests/runtests.pl.orig	Tue Dec 21 09:55:34 2004
+++ tests/runtests.pl	Tue Dec 21 09:55:07 2004
@@ -1599,7 +1599,7 @@
     }
     elsif ($ARGV[0] eq "-c") {
         # use this path to curl instead of default
-        $CURL=$ARGV[1];
+        $CURL=$DBGCURL=$ARGV[1];
         shift @ARGV;
     }
     elsif ($ARGV[0] eq "-d") {
