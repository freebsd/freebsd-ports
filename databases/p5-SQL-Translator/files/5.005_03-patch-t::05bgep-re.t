--- t/05bgep-re.t.orig	Sun May  9 19:03:10 2004
+++ t/05bgep-re.t	Sun May  9 19:03:27 2004
@@ -44,7 +44,7 @@
                                 SUFFIX => '.xml',
                                 DIR => tmpdir);
     print $fh $data;
-    $fh->close;
+    close $fh;
 
     ok(XML::Parser->new->parsefile($fname),
         "Successfully parsed output");
