- patch includes removal of '-arch i386' trying to fix build on i386:
- see https://github.com/ncbi/ngs/issues/39

--- ngs-sdk/setup/konfigure.perl.orig	2022-11-15 17:37:36 UTC
+++ ngs-sdk/setup/konfigure.perl
@@ -225,7 +225,7 @@ println $MARCH unless ($AUTORUN);
 
 print "checking machine architecture... " unless ($AUTORUN);
 println $MARCH unless ($AUTORUN);
-unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i || $MARCH =~ /aarch64/) {
+unless ($MARCH =~ /x86_64/i || $MARCH =~ /amd64/i || $MARCH =~ /i?86/i || $MARCH =~ /aarch64/) {
     println "configure: error: unsupported architecture '$OSTYPE':'$MARCH'";
     exit 1;
 }
@@ -312,6 +312,8 @@ if ($MARCH =~ /x86_64/i) {
 
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
@@ -386,14 +398,14 @@ if ($TOOLS =~ /gcc$/) {
     my $versionMin = '-mmacosx-version-min=10.10';
     $CP   = "$CPP -c $versionMin";
     if ($BITS ne '32_64') {
-        $ARCH_FL = '-arch i386' if ($BITS == 32);
+        $ARCH_FL = '' if ($BITS == 32);
         $OPT = '-O3';
         $AR      = 'ar rc';
         $LD      = "clang $ARCH_FL";
         $LP      = "$CPP $versionMin $ARCH_FL";
     } else {
         $MAKE_MANIFEST = '( echo "$^" > $@/manifest )';
-        $ARCH_FL       = '-arch i386 -arch x86_64';
+        $ARCH_FL       = '-arch x86_64';
         $OPT    = '-O3';
         $AR     = 'libtool -static -o';
         $LD     = "clang -Wl,-arch_multiple $ARCH_FL -Wl,-all_load";
