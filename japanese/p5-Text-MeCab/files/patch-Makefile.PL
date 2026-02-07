--- Makefile.PL.orig	2010-05-19 09:21:41.000000000 +0900
+++ Makefile.PL	2010-07-03 02:52:50.694347458 +0900
@@ -5,8 +5,8 @@
 my $RUNNING_IN_HELL = $^O eq 'MSWin32';
 
 my $config = run_probes();
-check_lib($config);
 define_symbols($config);
+push(@{ $config->{define} }, $config->{cflags});
 extract_constants($config);
 
 name 'Text-MeCab';
