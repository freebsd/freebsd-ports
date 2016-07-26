--- shairport.pl.orig	2012-01-02 10:57:00 UTC
+++ shairport.pl
@@ -270,6 +270,7 @@ $SIG{__DIE__} = sub {
 $avahi_publish = fork();
 my $pw_clause = (length $password) ? "pw=true" : "pw=false";
 if ($avahi_publish==0) {
+    open STDERR,  "/dev/null"; # suppress output from avahi-publish-service
     { exec 'avahi-publish-service',
         join('', map { sprintf "%02X", $_ } @hw_addr) . "\@$apname",
         "_raop._tcp",
@@ -329,7 +330,6 @@ my $sel = new IO::Select($listen);
 
 if ($daemon) {
     chdir "/" or die "Could not chdir to '/': $!";
-    umask 0;
     open STDIN, "/dev/null" or die "Could not redirect /dev/null to STDIN(0): $!";
     open STDOUT, ">/dev/null" or die "Could not redirect STDOUT(1) to /dev/null: $!";
     defined( my $pid = fork() ) or die "Could not fork: $!";
