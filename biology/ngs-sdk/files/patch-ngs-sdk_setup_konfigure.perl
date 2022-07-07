--- ngs-sdk/setup/konfigure.perl.orig	2021-08-18 16:26:23 UTC
+++ ngs-sdk/setup/konfigure.perl
@@ -225,7 +225,7 @@ if ($OS eq 'linux') {
 
 print "checking machine architecture... " unless ($AUTORUN);
 println $MARCH unless ($AUTORUN);
-unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i || $MARCH =~ /aarch64/) {
+unless ($MARCH =~ /x86_64/i || $MARCH =~ /amd64/i || $MARCH =~ /i?86/i || $MARCH =~ /aarch64/) {
     println "configure: error: unsupported architecture '$OSTYPE':'$MARCH'";
     exit 1;
 }
@@ -312,6 +312,8 @@ my $BITS;
 
 if ($MARCH =~ /x86_64/i) {
     $BITS = 64;
+} elsif ($MARCH =~ /amd64/i) {
+    $BITS = 64;
 } elsif ($MARCH eq 'fat86') {
     $BITS = '32_64';
 } elsif ($MARCH =~ /i?86/i) {
@@ -337,6 +339,16 @@ if ($OSTYPE =~ /linux/i) {
     $OSINC = 'unix';
     $TOOLS = 'gcc' unless ($TOOLS);
     $PYTHON = 'python';
+} elsif ($OSTYPE =~ /freebsd/i) {
+    $LPFX = 'lib';
+    $OBJX = 'o';
+    $LOBX = 'pic.o';
+    $LIBX = 'a';
+    $SHLX = 'so';
+    $EXEX = '';
+    $OSINC = 'unix';
+    $TOOLS = 'clang' unless ($TOOLS);
+    $PYTHON = $ENV{FREEBSD_PYTHON_CMD};
 } elsif ($OSTYPE =~ /darwin/i) {
     $LPFX = 'lib';
     $OBJX = 'o';
