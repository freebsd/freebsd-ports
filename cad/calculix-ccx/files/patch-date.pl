--- date.pl.orig	2024-08-05 17:13:21 UTC
+++ date.pl
@@ -1,6 +1,7 @@
 #!/usr/bin/env perl
 
-chomp($date=`date`);
+use POSIX qw(strftime);
+chomp(my $date = strftime("%Y-%m-%d", gmtime($ENV{SOURCE_DATE_EPOCH} || time)));
 
 # inserting the date into ccx_2.22.c
 
