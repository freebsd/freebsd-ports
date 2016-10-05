--- ../slimserver-vendor-14cc392/CPAN/buildme.sh.orig	2016-08-12 14:27:39.000000000 +0100
+++ ../slimserver-vendor-14cc392/CPAN/buildme.sh	2016-08-17 21:24:10.394225000 +0100
@@ -92,7 +92,7 @@
     exit
 fi
 
-for i in gcc cpp rsync make rsync ; do
+for i in cc cpp rsync make rsync ; do
     which $i > /dev/null
     if [ $? -ne 0 ] ; then
         echo "$i not found - please install it"
@@ -552,7 +552,7 @@
                     ICUOS="FreeBSD"
                 fi
                 CFLAGS="$ICUFLAGS" CXXFLAGS="$ICUFLAGS" LDFLAGS="$FLAGS $OSX_ARCH $OSX_FLAGS" \
-                    ./runConfigureICU $ICUOS --prefix=$BUILD --enable-static --with-data-packaging=archive
+                    ./configure --prefix=$BUILD --enable-static --with-data-packaging=archive
                 $MAKE
                 if [ $? != 0 ]; then
                     echo "make failed"
@@ -1223,6 +1223,9 @@
     if [ "$ARCH" = "amd64-freebsd" -o "$ARCH" = "amd64-freebsd-thread-multi" ]; then
         FFOPTS="$FFOPTS --arch=x86"
     fi
+    if [ "$OS" = "FreeBSD" ]; then
+	FFOPTS="$FFOPTS --cc=clang"
+    fi
     
     if [ "$OS" = "Darwin" ]; then
         SAVED_FLAGS=$FLAGS
