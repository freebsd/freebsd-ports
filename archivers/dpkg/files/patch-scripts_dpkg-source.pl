--- scripts/dpkg-source.pl.orig	Tue Jun 20 20:40:27 2006
+++ scripts/dpkg-source.pl	Fri Nov 10 13:26:54 2006
@@ -1,6 +1,7 @@
 #! /usr/bin/perl
 
 my $dpkglibdir = ".";
+my $prefix = "/usr"; # This line modified by Makefile
 my $version = "1.3.0"; # This line modified by Makefile
 
 my @filesinarchive;
@@ -616,10 +617,17 @@
     close(DSC);
 
     if ($is_signed) {
-	if (-x '/usr/bin/gpg') {
+	my $have_gpg = 0;
+	foreach my $path (split ':', $ENV{PATH}) {
+	    if (-x "$path/gpg") {
+		$have_gpg = 1;
+		last;
+	    }
+	}
+	if ($have_gpg) {
 	    my $gpg_command = 'gpg -q --verify ';
-	    if (-r '/usr/share/keyrings/debian-keyring.gpg') {
-		$gpg_command = $gpg_command.'--keyring /usr/share/keyrings/debian-keyring.gpg ';
+	    if (-r "$prefix/share/apt/keyrings/freebsd-keyring.gpg") {
+		$gpg_command = $gpg_command."--keyring $prefix/share/apt/keyrings/freebsd-keyring.gpg ";
 	    }
 	    $gpg_command = $gpg_command.quotemeta($dsc).' 2>&1';
 
@@ -842,18 +850,18 @@
 	    open DIFF, $patch or &error(sprintf(_g("can't open diff `%s'"), $patch));
 	}
 
-        defined($c2= fork) || &syserr(_g("fork for patch"));
+        defined($c2= fork) || &syserr(_g("fork for gpatch"));
         if (!$c2) {
-            open(STDIN,"<&DIFF") || &syserr(_g("reopen gzip for patch"));
-            chdir($newdirectory) || &syserr(sprintf(_g("chdir to %s for patch"), $newdirectory));
+            open(STDIN,"<&DIFF") || &syserr(_g("reopen gzip for gpatch"));
+            chdir($newdirectory) || &syserr(sprintf(_g("chdir to %s for gpatch"), $newdirectory));
 	    $ENV{'LC_ALL'}= 'C';
 	    $ENV{'LANG'}= 'C';
-            exec('patch','-s','-t','-F','0','-N','-p1','-u',
-                 '-V','never','-g0','-b','-z','.dpkg-orig') or &syserr(_g("exec patch"));
+            exec('gpatch','-s','-t','-F','0','-N','-p1','-u',
+                 '-V','never','-g0','-b','-z','.dpkg-orig') or &syserr(_g("exec gpatch"));
         }
         close(DIFF);
-        $c2 == waitpid($c2,0) || &syserr(_g("wait for patch"));
-        $? && subprocerr("patch");
+        $c2 == waitpid($c2,0) || &syserr(_g("wait for gpatch"));
+        $? && subprocerr("gpatch");
 
 	&reapgzip if $patch =~ /\.(gz|bz2)$/;
     }
@@ -909,7 +917,7 @@
     open(STDIN,"< $dscdir/$f") || &syserr(sprintf(_g("cannot read %s"), "$dscdir/$f"));
     (@s= stat(STDIN)) || &syserr(sprintf(_g("cannot fstat %s"), "$dscdir/$f"));
     $s[7] == $size{$f} || &error(sprintf(_g("file %s has size %s instead of expected %s"), $f, $s[7], $size{$f}));
-    $m= `md5sum`; $? && subprocerr("md5sum $f"); $m =~ s/\n$//;
+    $m= `gmd5sum`; $? && subprocerr("gmd5sum $f"); $m =~ s/\n$//;
     $m = readmd5sum( $m );
     $m eq $md5sum{$f} || &error(sprintf(_g("file %s has md5sum %s instead of expected %s"), $f, $m, $md5sum{$f}));
     open(STDIN,"</dev/null") || &syserr(_g("reopen stdin from /dev/null"));
@@ -1334,8 +1342,8 @@
 	&internerr( sprintf(_g("tried to add file `%s' twice"), $filename));
     stat($filename) || &syserr(sprintf(_g("could not stat output file `%s'"), $filename));
     $size= (stat _)[7];
-    my $md5sum= `md5sum <$filename`;
-    $? && &subprocerr("md5sum $filename");
+    my $md5sum= `gmd5sum <$filename`;
+    $? && &subprocerr("gmd5sum $filename");
     $md5sum = readmd5sum( $md5sum );
     $f{'Files'}.= "\n $md5sum $size $filename";
 }
