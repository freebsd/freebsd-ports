--- plgrenouille.pl.orig	Fri Oct  3 16:00:23 2003
+++ plgrenouille.pl	Thu Mar  4 15:58:57 2004
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -Tw
+#!%%PERL%% -Tw
 # plgrenouille 0.70       -- don't forget to update Grenouille::Vars
 # version 0.4 by momtchev, <momtchev@fil.univ-lille1.fr>
 # modified by Pierre Etchemaite, <petchema@concept-micro.com>
@@ -19,6 +19,7 @@
 use Grenouille::Vars qw(%VERSION %DEBUG
                         $MYRC $DATAPATH $DOWNLOADFILE $UPLOADFILE $QUEUEFILE
                         $LASTCONFIGFILE $LASTVERSIONFILE $PIDFILE
+			$BEFOREFILE $AFTERFILE
                         $ASAP $SEC $MIN $DAY
                         %vars);
 use Grenouille::Numbers qw(digits jitter);
@@ -35,7 +36,7 @@
 use Grenouille::System qw(init_privileges swap_privileges
                           autodetect_interface get_traffic_counters);
 
-$ENV{'PATH'} = '/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin';
+$ENV{'PATH'} = '%%PREFIX%%/sbin:%%PREFIX%%/bin:/usr/sbin:/usr/bin:/sbin:/bin';
 
 # ---------------------------------------------------------------
 
@@ -243,9 +244,9 @@
 sub before_test() {
 # stop or pause processes that could interfere with bandwidth measurements,
 # etc.
-    if(-x '/etc/plgrenouille-before') {
+    if(-x '$BEFOREFILE') {
 	eval {
-	    system '/etc/plgrenouille-before';
+	    system '$BEFOREFILE';
 	};
 	display_and_log('ERROR', "plgrenouille-before: $@") if $@;
     }
@@ -253,9 +254,9 @@
 
 sub after_test() {
 # revert anything done by before_test()
-    if(-x '/etc/plgrenouille-after') {
+    if(-x '$AFTERFILE') {
 	eval {
-	    system '/etc/plgrenouille-after';
+	    system '$AFTERFILE';
 	};
 	display_and_log('ERROR', "plgrenouille-after: $@") if $@;
     }
@@ -620,8 +621,6 @@
 
 # --------------------------- MAIN ----------------------------
 
-display_version();
-
 Getopt::Long::Configure('bundling'); # 'no_ignore_case'
 eval {
   GetOptions(\%params,
@@ -629,6 +628,7 @@
              'verbose|v=s', \&set_verbose_level,
              'configure|setup|c',
              'background|b',
+             'version|V',
              'help|h|?');
 };
 if ($@) {
@@ -637,6 +637,10 @@
 }
 usage(1) if scalar @ARGV;
 usage(0) if $params{'help'};
+if($params{'version'}) {
+    display_version();
+    exit(0);
+}
 
 open_log();
 init_grenouille();
