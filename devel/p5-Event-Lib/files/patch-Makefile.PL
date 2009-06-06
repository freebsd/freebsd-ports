--- Makefile.PL.orig	Tue Mar  7 08:37:40 2006
+++ Makefile.PL	Mon Jun  5 23:31:13 2006
@@ -2,7 +2,11 @@
 use ExtUtils::MakeMaker;
 use Config;
 
-my %args = map { split /\s*=\s*/ } @ARGV;
+my %args;
+foreach $_ (@ARGV){
+    m/(.*?)=(.*)/;
+    $args{$1} = $2;
+}
 
 # purge @ARGV of CCFLAGS
 
--- Makefile.PL
+++ Makefile.PL
@@ -17,8 +17,9 @@ sub have_libevent {
     my $LIBS = $args{ LIBS } || "-levent";
     my $INC = $args{ INC } || "-I/usr/include";
     if ($^O eq "freebsd") {
-      $LIBS = "$LIBS -L/usr/local/lib";
-      $INC  = "$INC -I/usr/local/include";
+      my $LOCALBASE = $ENV{LOCALBASE} || '/usr/local';
+      $LIBS .= " -L$LOCALBASE/lib";
+      $INC  .= " -I$LOCALBASE/include";
     }
     elsif ($^O eq "darwin") {
       $LIBS = "$LIBS -L/sw/lib -L/opt/local/lib";
@@ -59,8 +60,9 @@ sub get_defines {
     my $LIBS = $args{ LIBS } || "-levent";
     my $INC = $args{ INC } || "-I/usr/include";
     if ($^O eq "freebsd") {
-      $LIBS = "-L/usr/local/lib $LIBS";
-      $INC  = "-I/usr/local/include $INC";
+      my $LOCALBASE = $ENV{LOCALBASE} || '/usr/local';
+      $LIBS = "-L$LOCALBASE/lib $LIBS";
+      $INC  = "-I$LOCALBASE/include $INC";
     }
     elsif ($^O eq "darwin") {
       $LIBS = "-L/sw/lib -L/opt/local/lib $LIBS";
@@ -100,6 +102,12 @@ EOD
 
 $args{LIBS} = '-levent -lm' if ! exists $args{LIBS};
 
+if ($^O eq "freebsd") {
+    my $LOCALBASE = $ENV{LOCALBASE} || '/usr/local';
+    $args{LIBS} .= " -L$LOCALBASE/lib";
+    $args{INC} .= " -I$LOCALBASE/include";
+}
+
 my $DEFINES = get_defines(
     event_priority_init =>	{   code_pre	=> '',
 				    code	=> 'event_priority_init(10)',
