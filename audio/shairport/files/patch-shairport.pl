--- shairport.pl.orig	2012-01-08 22:34:35.000000000 +1000
+++ shairport.pl	2012-01-08 22:34:14.000000000 +1000
@@ -270,6 +270,7 @@
 $avahi_publish = fork();
 my $pw_clause = (length $password) ? "pw=true" : "pw=false";
 if ($avahi_publish==0) {
+    open STDERR,  "/dev/null"; # suppress output from avahi-publish-service
     { exec 'avahi-publish-service',
         join('', map { sprintf "%02X", $_ } @hw_addr) . "\@$apname",
         "_raop._tcp",
@@ -329,7 +330,6 @@
 
 if ($daemon) {
     chdir "/" or die "Could not chdir to '/': $!";
-    umask 0;
     open STDIN, "/dev/null" or die "Could not redirect /dev/null to STDIN(0): $!";
     open STDOUT, ">/dev/null" or die "Could not redirect STDOUT(1) to /dev/null: $!";
     defined( my $pid = fork() ) or die "Could not fork: $!";
