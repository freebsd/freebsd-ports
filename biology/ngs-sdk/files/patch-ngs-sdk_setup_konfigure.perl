--- ngs-sdk/setup/konfigure.perl.orig	2021-03-15 18:08:20 UTC
+++ ngs-sdk/setup/konfigure.perl
@@ -204,7 +204,7 @@ print "checking system type... " unless ($AUTORUN);
 my ($OS, $ARCH, $OSTYPE, $MARCH, @ARCHITECTURES) = OsArch();
 println $OSTYPE unless ($AUTORUN);
 
-unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win') {
+unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /freebsd/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win') {
     println "configure: error: unsupported system '$OSTYPE'";
     exit 1;
 }
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
@@ -337,6 +339,25 @@ if ($OSTYPE =~ /linux/i) {
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
+} elsif ($OSTYPE =~ /darwin/i) {
+    $LPFX = 'lib';
+    $OBJX = 'o';
+    $LOBX = 'pic.o';
+    $LIBX = 'a';
+    $SHLX = 'dylib';
+    $EXEX = '';
+    $OSINC = 'unix';
+    $TOOLS = 'clang' unless ($TOOLS);
 } elsif ($OSTYPE =~ /darwin/i) {
     $LPFX = 'lib';
     $OBJX = 'o';
