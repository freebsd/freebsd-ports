--- date.pl.orig	2021-12-17 12:13:23 UTC
+++ date.pl
@@ -1,6 +1,7 @@
 #!/usr/bin/env perl
 
-chomp($date=`date`);
+use POSIX qw(strftime);
+chomp(my $date = strftime("%Y-%m-%d", gmtime($ENV{SOURCE_DATE_EPOCH} || time)));
 
 # inserting the date into ccx_2.19.c
 
