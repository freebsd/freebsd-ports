#iz 32769
http://qa.openoffice.org/issues/show_bug.cgi?id=32769
temporary fix.

Index: langren.pl
===================================================================
RCS file: /cvs/installation/helpcontent/langren.pl,v
retrieving revision 1.4
diff -u -r1.4 langren.pl
--- ../helpcontent/langren.pl.org	12 Jul 2004 12:43:08 -0000	1.4
+++ ../helpcontent/langren.pl	10 Aug 2004 07:58:54 -0000
@@ -123,7 +123,7 @@
         }
     } else {
         system("mkdir -p $dest_dir");
-        my $cpcmd = ( -x "$ENV{'BUILD_TOOLS'}/gnucp" ? "$ENV{BUILD_TOOLS}/gnucp" : "cp" );
+        my $cpcmd = ( -x "$ENV{'GNUCOPY'}" ? "$ENV{'GNUCOPY'}" : "cp" );
         if ( system("$cpcmd -r -u $src_dir/* $dest_dir")) {
             print STDERR "error while copying\n";
             unlink ".langren_working";
