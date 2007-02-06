--- scripts/dpkg-scansources.pl.orig	Sun Jun 18 18:22:03 2006
+++ scripts/dpkg-scansources.pl	Mon Nov 13 21:31:23 2006
@@ -298,11 +298,11 @@
     if (!$pid) {
 	open STDIN, '<&FILE' or xdie sprintf(_g("can't dup %s:"), $file);
 	seek STDIN, 0, 0     or xdie sprintf(_g("can't rewind %s:"), $file);
-	exec 'md5sum'        or xdie _g("can't exec md5sum:");
+	exec 'gmd5sum'        or xdie _g("can't exec gmd5sum:");
     }
     chomp($md5 = join '', <MD5>);
     unless (close MD5) {
-	xwarn_noerror close_msg 'md5sum';
+	xwarn_noerror close_msg 'gmd5sum';
 	return;
     }
     $md5 =~ s/ *-$//; # Remove trailing spaces and -, to work with GNU md5sum
