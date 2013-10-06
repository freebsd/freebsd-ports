--- Makefile.PL.orig	2006-09-27 08:46:57.000000000 +0000
+++ Makefile.PL
@@ -9,6 +9,10 @@ if ($^O =~ /linux/) {
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
