--- scripts/dpkg-genchanges.pl.orig	Wed Jun 28 17:14:04 2006
+++ scripts/dpkg-genchanges.pl	Mon Nov 13 21:29:46 2006
@@ -336,9 +336,9 @@
     open(STDIN,"< $uf") || &syserr(sprintf(_g("cannot open upload file %s for reading"), $uf));
     (@s=stat(STDIN)) || &syserr(sprintf(_g("cannot fstat upload file %s"), $uf));
     $size= $s[7]; $size || &warn(sprintf(_g("upload file %s is empty"), $uf));
-    $md5sum=`md5sum`; $? && subprocerr(sprintf(_g("md5sum upload file %s"), $uf));
+    $md5sum=`gmd5sum`; $? && subprocerr(sprintf(_g("gmd5sum upload file %s"), $uf));
     $md5sum =~ m/^([0-9a-f]{32})\s*-?\s*$/i ||
-        &failure(sprintf(_g("md5sum upload file %s gave strange output \`%s'"), $uf, $md5sum));
+        &failure(sprintf(_g("gmd5sum upload file %s gave strange output \`%s'"), $uf, $md5sum));
     $md5sum= $1;
     defined($md5sum{$f}) && $md5sum{$f} ne $md5sum &&
         &error(sprintf(_g("md5sum of source file %s (%s) is different ".
