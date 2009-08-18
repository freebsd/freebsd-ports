--- bin/SetPermissions.pl
+++ bin/SetPermissions.pl
@@ -174,6 +174,7 @@
     "$DestDir/.fetchmailrc",
 );
 for my $Dir (@Dirs) {
+    next unless -e $Dir;
     print "Setting owner rw and group ro permissions on $Dir\n";
     $_ = $Dir;
     makeReadOnly();
