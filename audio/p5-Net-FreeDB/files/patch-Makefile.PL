--- Makefile.PL.orig	2014-10-15 18:10:11 UTC
+++ Makefile.PL
@@ -12,6 +12,10 @@ if ($^O =~ /linux/) {
         print "OS: $^O, copying XS file: ";
         system("cp FreeDB.xs.linux FreeDB.xs") && die "Copying failed\n";
         print "1 file copied\n";
+} elsif ($^O =~ /dragonfly/) {
+        print "OS: $^O, copying XS file: ";
+        system("cp FreeDB.xs.linux FreeDB.xs") && die "Copying failed\n";
+        print "1 file copied\n";
 } elsif ($^O =~ /MSWin32/) {
         print "OS: $^O, copying XS file:";
         system("copy FreeDB.xs.win32 FreeDB.xs") && die "Copying failed\n";
