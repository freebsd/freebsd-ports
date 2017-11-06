--- ../slimserver-vendor-1463b00/CPAN/buildme.sh.orig	2017-06-07 14:29:20.000000000 +0100
+++ ../slimserver-vendor-1463b00/CPAN/buildme.sh	2017-07-12 21:44:11.808290000 +0100
@@ -92,7 +92,7 @@
     exit
 fi
 
-for i in gcc cpp rsync make rsync ; do
+for i in cc cpp rsync make rsync ; do
     which $i > /dev/null
     if [ $? -ne 0 ] ; then
         echo "$i not found - please install it"
@@ -556,6 +556,19 @@
             # because it takes so damn long on slow platforms
             if [ ! -f build/lib/libicudata_s.a ]; then
                 tar_wrapper zxvf icu4c-4_6-src.tgz
+		patch << END
+--- icu/source/i18n/uspoof.cpp.orig     2017-07-12 21:35:34.014645000 +0100
++++ icu/source/i18n/uspoof.cpp  2017-07-12 21:33:44.790884000 +0100
+@@ -366,7 +366,7 @@
+         // u_strToUTF8() in preflight mode is an easy way to do it.
+         U_ASSERT(position16 <= len16);
+         u_strToUTF8(NULL, 0, position, text16, position16, status);
+-        if (position > 0) {
++        if (position != NULL && *position > 0) {
+             // position is the required buffer length from u_strToUTF8, which includes
+             // space for a terminating NULL, which we don't want, hence the -1.
+             *position -= 1;
+END
                 cd icu/source
                 if [ "$OS" = 'Darwin' ]; then
                     ICUFLAGS="$FLAGS $OSX_ARCH $OSX_FLAGS -DU_USING_ICU_NAMESPACE=0 -DU_CHARSET_IS_UTF8=1" # faster code for native UTF-8 systems
@@ -568,7 +581,7 @@
                     ICUOS="FreeBSD"
                 fi
                 CFLAGS="$ICUFLAGS" CXXFLAGS="$ICUFLAGS" LDFLAGS="$FLAGS $OSX_ARCH $OSX_FLAGS" \
-                    ./runConfigureICU $ICUOS --prefix=$BUILD --enable-static --with-data-packaging=archive
+                    ./configure --prefix=$BUILD --enable-static --with-data-packaging=archive
                 $MAKE
                 if [ $? != 0 ]; then
                     echo "make failed"
@@ -1239,6 +1252,9 @@
     if [ "$ARCH" = "amd64-freebsd" -o "$ARCH" = "amd64-freebsd-thread-multi" ]; then
         FFOPTS="$FFOPTS --arch=x86"
     fi
+    if [ "$OS" = "FreeBSD" ]; then
+	FFOPTS="$FFOPTS --cc=clang"
+    fi
     
     if [ "$OS" = "Darwin" ]; then
         SAVED_FLAGS=$FLAGS
