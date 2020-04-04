--- ngs-sdk/setup/konfigure.perl.orig	2020-04-01 16:34:36 UTC
+++ ngs-sdk/setup/konfigure.perl
@@ -202,7 +202,7 @@ print "checking system type... " unless ($AUTORUN);
 my ($OS, $ARCH, $OSTYPE, $MARCH, @ARCHITECTURES) = OsArch();
 println $OSTYPE unless ($AUTORUN);
 
-unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win') {
+unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win' || $OSTYPE eq 'FreeBSD') {
     println "configure: error: unsupported system '$OSTYPE'";
     exit 1;
 }
@@ -221,6 +221,10 @@ if ($OS eq 'linux') {
     println $OS_DISTRIBUTOR unless ($AUTORUN);
 }
 
+if ($MARCH eq 'amd64') {
+    $MARCH = 'x86_64';
+}
+
 print "checking machine architecture... " unless ($AUTORUN);
 println $MARCH unless ($AUTORUN);
 unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i) {
@@ -333,6 +337,16 @@ if ($OSTYPE =~ /linux/i) {
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
+    $PYTHON = 'python';
 } elsif ($OSTYPE =~ /darwin/i) {
     $LPFX = 'lib';
     $OBJX = 'o';
@@ -379,11 +393,11 @@ if ($TOOLS =~ /gcc$/) {
 } elsif ($TOOLS eq 'clang') {
     $CPP  = 'clang++' unless ($CPP);
     $CC   = 'clang -c';
-    my $versionMin = '-mmacosx-version-min=10.10';
+    my $versionMin = '';
     $CP   = "$CPP -c $versionMin";
     if ($BITS ne '32_64') {
         $ARCH_FL = '-arch i386' if ($BITS == 32);
-        $OPT = '-O3';
+        $OPT = $ENV{'CXXFLAGS'};
         $AR      = 'ar rc';
         $LD      = "clang $ARCH_FL";
         $LP      = "$CPP $versionMin $ARCH_FL";
@@ -508,7 +522,7 @@ foreach my $href (DEPENDS()) {
             $I = $t if (-e $t);
         }
         push ( @L, File::Spec->catdir($OPT{$o}, 'lib') );
-        push ( @L, File::Spec->catdir($OPT{$o}, 'lib64') );
+        #push ( @L, File::Spec->catdir($OPT{$o}, 'lib64') );
     }
     my ($i, $l) = find_lib($_, $I, @L);
     if (defined $i || $l) {
@@ -929,8 +943,7 @@ EndText
     L($F, "PIC     = $PIC") if ($PIC);
     if ($PKG{LNG} eq 'C') {
         if ($TOOLS =~ /clang/i) {
-   L($F, 'SONAME  = -install_name ' .
-               '$(INST_LIBDIR)$(BITS)/$(subst $(VERSION),$(MAJVERS),$(@F)) \\');
+   L($F, 'SONAME = -Wl,-soname=$(subst $(VERSION),$(MAJVERS),$(@F)) \\');
    L($F, '    -compatibility_version $(MAJMIN) -current_version $(VERSION) \\');
    L($F, '    -flat_namespace -undefined suppress');
         } else {
