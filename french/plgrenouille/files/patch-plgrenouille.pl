--- plgrenouille.pl.orig	Tue Nov  5 19:42:49 2002
+++ plgrenouille.pl	Wed Nov 13 15:51:51 2002
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -Tw
+#!%%PERL%% -Tw
 # plgrenouille 0.61
 # version 0.4 by momtchev, <momtchev@fil.univ-lille1.fr>
 # modified by Pierre Etchemaite, <petchema@concept-micro.com>
@@ -18,7 +18,7 @@
 use Net::Ping qw();
 use Net::FTP qw();
 
-$ENV{'PATH'} = '/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin';
+$ENV{'PATH'} = '%%PREFIX%%/sbin:%%PREFIX%%/bin:/usr/sbin:/usr/bin:/sbin:/bin';
 
 my(%VERSION) = ( 'client' => 'plgrenouille',
 		 'version' => 0.61,
@@ -28,17 +28,20 @@
 		               # where anyone can fork his own version
 		 'system' => $^O );
 
-my $MYRC ||= '/etc/grenouillerc';
-my $DATAPATH ||= '/var/spool/plgrenouille';
+my $PREFIX ||= '%%PREFIX%%';
+my $MYRC ||= "$PREFIX/etc/grenouillerc";
+my $DATAPATH ||= '%%SPOOL_DIR%%';
 my $DOWNLOADFILE ||= "$DATAPATH/downloadfile";
 my $UPLOADFILE ||= "$DATAPATH/uploadfile";
 my $QUEUEFILE ||= "$DATAPATH/queued_results.txt";
 my $LASTCONFIGFILE ||= "$DATAPATH/last_configuration.txt";
 my $LASTVERSIONFILE ||= "$DATAPATH/last_known_version.txt";
-my $PIDFILE ||= "/var/run/plgrenouille.pid";
-my $LOGFILE ||= "/var/log/plgrenouille.log";
+my $PIDFILE ||= "%%RUN_DIR%%/plgrenouille.pid";
+my $LOGFILE ||= "%%LOG_DIR%%/plgrenouille.log";
+my $NETSTAT ||= '/usr/bin/netstat';
+my $IFCONFIG ||= '/sbin/ifconfig';
 
-my $USER ||= 'daemon';
+my $USER ||= '%%SPOOL_USER%%';
 
 # what features do we want to debug ?
 my(%DEBUG) = ( 'protocol' => 0, 'scheduler' => 0 );
@@ -61,6 +64,7 @@
 
 sub usage($) {
     my($exitcode) = @_;
+    display_version();
     print <<"EOUSAGE";
 Usage: $VERSION{'client'} [-c|--configure] [-b|--background] [-h|-?|--help]
               [[-l |--log=]priorité] [[-v |--verbose=]priorité]
@@ -101,7 +105,7 @@
 
 # for milliseconds; otherwise would use built-in time.
 
-my $SYS_gettimeofday ||= 78;
+my $SYS_gettimeofday ||= 116;
 
 sub microtime() {
     my ($timeval, $timezone, $sec, $usec);
@@ -187,36 +191,21 @@
   die "Priorité $level inconnue" unless $DISPLAY_LEVEL;
 }
 
-# parse /proc/net/dev (Linux)
+# parse netstat -ib (FreeBSD)
 sub get_traffic_counters($) {
     my ($if_device) = @_;
     
-    # Sometimes fails with EOVERFLOW ("Value too large for defined data type")
-    # on my box, maybe some LFS bug in /proc ? (kernel 2.4.5)
-    open(PROC_NET_DEV, '</proc/net/dev') or 
-	die "Can't read /proc/net/dev: $!";
-    while (<PROC_NET_DEV>) {
-	if (/^\s*$if_device:\s*(.*)$/) {
+    open(NETSTAT_PIPE, '-|') or exec($NETSTAT, '-ib') or die "netstat: $!";
+    while (<NETSTAT_PIPE>) {
+	if (/^($if_device.*<Link.*)/) {
 	    my(@counters) = split(/\s+/, $1);
-	    close(PROC_NET_DEV);
-	    if(scalar @counters == 16) {
-		# linux >2.1.90
-		return { 'rx' => $counters[0],
-			 'tx' => $counters[8] };
-	    }
-	    if(scalar @counters == 14) {
-		# linux 2.1.0..2.1.90
-		return { 'rx' => $counters[0],
-			 'tx' => $counters[6] };
-	    }
-	    if(scalar @counters == 11) {
-		die 'Désolé, les noyaux antérieurs à 2.1.0 ne sont pas supportés';
-	    }
-	    die 'Format de /proc/net/dev non reconnu, envoyer un exemple au mainteneur SVP';
+	    close(NETSTAT_PIPE);
+	    return { 'rx' => $counters[6],
+		     'tx' => $counters[9] };
 	}
     }
     
-    close(PROC_NET_DEV);
+    close(NETSTAT_PIPE);
     die "Pas d'interface $if_device ?";
 }
 
@@ -332,6 +321,7 @@
 }
 
 sub load_preferences() {
+    swap_privileges();
     eval {
 	if (open(CONFIG, "<$MYRC")) {
 	    while (<CONFIG>) {
@@ -343,10 +333,12 @@
 	}
     };
     die if $@;
+    swap_privileges();
 }
 
 sub store_preferences() {
     my($oldumask) = umask 0177;
+    swap_privileges();
     eval {
 	if(open(CONFIG, ">$MYRC")) {
 	    map { print CONFIG "$_=$preferences{$_}\n"; } sort keys %preferences;
@@ -355,6 +347,7 @@
 	    display_and_log('WARNING', "Ecriture du fichier $MYRC impossible: vérifier les permissions");
 	}
     };
+    swap_privileges();
     umask $oldumask;
     die if $@;
 }
@@ -420,7 +413,7 @@
 sub get_preferences() {
     load_preferences();
     
-    die "plgrenouille n'a pas été totalement paramétré, lancez plgrenouille --config ou modifiez /etc/grenouillerc" 
+    die "plgrenouille n'a pas été totalement paramétré, lancez plgrenouille --config ou modifiez $MYRC"
 	if not defined $preferences{'user'} or 
 	   not defined $preferences{'pass'} or
 	   not defined $preferences{'email'} or 
@@ -434,20 +427,20 @@
 # plgrenouille uses the default route interface
 sub autodetect_interface() {
     $vars{'ip'} = '';
-    open(ROUTE, '-|') or exec('/bin/netstat', '-r') or die "netstat: $!";
-    while (<ROUTE>) {
-	if (/^default.*((?:eth|ppp|sl)[0-9]+)$/) {
+    open(ROUTE_PIPE, '-|') or exec($NETSTAT, '-r') or die "netstat: $!";
+    while (<ROUTE_PIPE>) {
+      if (/^default.* ([^ ]+[0-9]+)$/) {
 	    $preferences{'interface'} = $1;
-	}
+      }
     }
-    close(ROUTE);
-    open(IFCONFIG, '-|') or exec('/sbin/ifconfig', $preferences{'interface'}) or die "ifconfig: $!";
-    while(<IFCONFIG>) {
-	if (/inet add?r:([.0-9]+)/) {
+    close(ROUTE_PIPE);
+    open(IFCONFIG_PIPE, '-|') or exec($IFCONFIG, $preferences{'interface'}) or die "ifconfig: $!";
+    while(<IFCONFIG_PIPE>) {
+	if (/inet ([.0-9]+)/) {
 	    $vars{'ip'} = $1;
 	}
     }
-    close IFCONFIG;
+    close(IFCONFIG_PIPE);
     
     display_and_log('NOTICE', "$preferences{'interface'} sera utilisé pour les mesures") if $preferences{'interface'};
 }
@@ -1160,8 +1153,6 @@
 
 # --------------------------- MAIN ----------------------------
 
-display_version();
-
 Getopt::Long::Configure('bundling'); # 'no_ignore_case'
 eval {
   GetOptions(\%params,
@@ -1169,6 +1160,7 @@
              'verbose|v=s', \&set_verbose_level,
              'configure|setup|c',
              'background|b',
+             'version|V',
              'help|h|?');
 };
 if ($@) {
@@ -1177,6 +1169,10 @@
 }
 usage(1) if scalar @ARGV;
 usage(0) if $params{'help'};
+if($params{'version'}) {
+    display_version();
+    exit(0);
+}
 
 open_log();
 init_grenouille();
