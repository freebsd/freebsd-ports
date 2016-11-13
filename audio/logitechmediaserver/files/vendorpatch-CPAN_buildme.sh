--- ../slimserver-vendor-14cc392/CPAN/buildme.sh.orig	2016-08-12 21:27:39.000000000 +0800
+++ ../slimserver-vendor-14cc392/CPAN/buildme.sh	2016-11-13 13:08:08.765866000 +0800
@@ -92,7 +92,7 @@
     exit
 fi
 
-for i in gcc cpp rsync make rsync ; do
+for i in cc cpp rsync make rsync ; do
     which $i > /dev/null
     if [ $? -ne 0 ] ; then
         echo "$i not found - please install it"
@@ -309,6 +309,19 @@
     PERL_ARCH=$BUILD/arch/5.22
 fi
 
+# Path to Perl 5.24
+if [ -x "/usr/bin/perl5.24.1" ]; then
+    PERL_524=/usr/bin/perl5.24.1
+fi
+   
+if [ $PERL_524 ]; then
+    echo "Building with Perl 5.24 at $PERL_524"
+    PERL_BIN=$PERL_524
+    # Install dir for 5.24
+    PERL_BASE=$BUILD/5.24
+    PERL_ARCH=$BUILD/arch/5.24
+fi
+
 # try to use default perl version
 if [ "$PERL_BIN" = "" ]; then
     PERL_BIN=`which perl`
@@ -339,6 +352,9 @@
     "5.22")
         PERL_522=$PERL_BIN
         ;;
+    "5.24")
+	PERL_524=$PERL_BIN
+        ;;
     *)
         echo "Failed to find supported Perl version for '$PERL_BIN'"
         exit
@@ -504,7 +520,7 @@
             ;;
         
         Class::XSAccessor)
-            if [ "$PERL_516" -o "$PERL_518" -o "$PERL_520" -o "$PERL_522" ]; then
+            if [ "$PERL_516" -o "$PERL_518" -o "$PERL_520" -o "$PERL_522" -o "$PERL_524" ]; then
                 build_module Class-XSAccessor-1.18
                 cp -pR $PERL_BASE/lib/perl5/$ARCH/Class $PERL_ARCH/
             else
@@ -520,7 +536,7 @@
             ;;
         
         DBI)
-            if [ "$PERL_518" -o "$PERL_520" -o "$PERL_522" ]; then
+            if [ "$PERL_518" -o "$PERL_520" -o "$PERL_522" -o "$PERL_524" ]; then
                 build_module DBI-1.628
                 cp -p $PERL_BASE/lib/perl5/$ARCH/DBI.pm $PERL_ARCH/
                 cp -pR $PERL_BASE/lib/perl5/$ARCH/DBI $PERL_ARCH/
@@ -530,7 +546,7 @@
             ;;
         
         DBD::SQLite)
-            if [ "$PERL_518" -o "$PERL_520" -o "$PERL_522" ]; then
+            if [ "$PERL_518" -o "$PERL_520" -o "$PERL_522" -o "$PERL_524" ]; then
                 build_module DBI-1.628 "" 0
             else
                 build_module DBI-1.616 "" 0
@@ -552,7 +568,7 @@
                     ICUOS="FreeBSD"
                 fi
                 CFLAGS="$ICUFLAGS" CXXFLAGS="$ICUFLAGS" LDFLAGS="$FLAGS $OSX_ARCH $OSX_FLAGS" \
-                    ./runConfigureICU $ICUOS --prefix=$BUILD --enable-static --with-data-packaging=archive
+                    ./configure --prefix=$BUILD --enable-static --with-data-packaging=archive
                 $MAKE
                 if [ $? != 0 ]; then
                     echo "make failed"
@@ -616,7 +632,7 @@
                 rm -rf DBD-SQLite-1.34_01
             else
                 cd ..
-                if [ "$PERL_516" -o "$PERL_518" -o "$PERL_520" -o "$PERL_522" ]; then
+                if [ "$PERL_516" -o "$PERL_518" -o "$PERL_520" -o "$PERL_522" -o "$PERL_524" ]; then
                    build_module DBD-SQLite-1.34_01 "" 0
                 fi
                 build_module DBD-SQLite-1.34_01
@@ -698,7 +714,7 @@
         JSON::XS)
             build_module common-sense-2.0
             
-            if [ "$PERL_518" -o "$PERL_520" -o "$PERL_522" ]; then
+            if [ "$PERL_518" -o "$PERL_520" -o "$PERL_522" -o "$PERL_524" ]; then
                 build_module JSON-XS-2.34
                 cp -pR $PERL_BASE/lib/perl5/$ARCH/JSON $PERL_ARCH/
             else
@@ -728,7 +744,7 @@
             ;;
         
         YAML::LibYAML)
-            if [ "$PERL_516" -o "$PERL_518" -o "$PERL_520" -o "$PERL_522" ]; then
+            if [ "$PERL_516" -o "$PERL_518" -o "$PERL_520" -o "$PERL_522" -o "$PERL_524" ]; then
                 build_module YAML-LibYAML-0.35 "" 0
             else
                 build_module YAML-LibYAML-0.35
@@ -1223,6 +1239,9 @@
     if [ "$ARCH" = "amd64-freebsd" -o "$ARCH" = "amd64-freebsd-thread-multi" ]; then
         FFOPTS="$FFOPTS --arch=x86"
     fi
+    if [ "$OS" = "FreeBSD" ]; then
+	FFOPTS="$FFOPTS --cc=clang"
+    fi
     
     if [ "$OS" = "Darwin" ]; then
         SAVED_FLAGS=$FLAGS
@@ -1387,7 +1406,7 @@
 
 # create our directory structure
 # rsync is used to avoid copying non-binary modules or other extra stuff
-if [ "$PERL_512" -o "$PERL_514" -o "$PERL_516" -o "$PERL_518" -o "$PERL_520" -o "$PERL_522" ]; then
+if [ "$PERL_512" -o "$PERL_514" -o "$PERL_516" -o "$PERL_518" -o "$PERL_520" -o "$PERL_522" -o "$PERL_524" ]; then
     # Check for Perl using use64bitint and add -64int
     ARCH=`$PERL_BIN -MConfig -le 'print $Config{archname}' | sed 's/gnu-//' | sed 's/^i[3456]86-/i386-/' | sed 's/armv.*?-/arm-/' `
 fi
