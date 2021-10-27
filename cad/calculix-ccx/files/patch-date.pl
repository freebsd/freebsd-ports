--- date.pl.orig	2021-09-15 19:39:24 UTC
+++ date.pl
@@ -1,6 +1,7 @@
 #!/usr/bin/env perl
 
-chomp($date=`date`);
+use POSIX qw(strftime);
+chomp(my $date = strftime("%Y-%m-%d", gmtime($ENV{SOURCE_DATE_EPOCH} || time)));
 
 # inserting the date into ccx_2.18.c
 
