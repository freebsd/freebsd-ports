--- build.sh.orig	2012-10-11 18:40:23.000000000 -0500
+++ build.sh	2012-10-19 18:50:50.000000000 -0500
@@ -1,18 +1,19 @@
+export CC=cc
 set -e
 rm -rf build
 mkdir build
 cd build
-../binutils/configure --target=zpu-elf --prefix=`pwd`/../install
-make
-make install
+../binutils/configure --target=zpu-elf --prefix=%%PREFIX%%/zpu --infodir=%%PREFIX%%/info/zpu
+%%GMAKE%%
+#gmake install
 cd ..
 
-export PATH=`pwd`/install/bin:$PATH
-rm -rf gccbuild
-mkdir gccbuild
-cd gccbuild
-#../gcc/configure --target=zpu-elf --prefix=`pwd`/../install --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --disable-shared --enable-newlib -v --enable-checking=misc,tree,rtl,rtlflag,gc,gcac,fold  --disable-multilib --disable-threads --enable-sjlj-exceptions --enable-libstdcxx-allocator=malloc
-../gcc/configure --target=zpu-elf --prefix=`pwd`/../install --enable-languages=c --with-gnu-as --with-gnu-ld --with-newlib --disable-shared --enable-newlib -v --enable-checking=misc,tree,rtl,rtlflag,gc,gcac,fold  --disable-multilib --disable-threads --enable-sjlj-exceptions --enable-libstdcxx-allocator=malloc
-make
-make install
+#export PATH=/usr/local/zpu/bin:$PATH
+#rm -rf gccbuild
+#mkdir gccbuild
+#cd gccbuild
+##../gcc/configure --target=zpu-elf --prefix=/usr/local/zpu --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --disable-shared --enable-newlib -v --enable-checking=misc,tree,rtl,rtlflag,gc,gcac,fold  --disable-multilib --disable-threads --enable-sjlj-exceptions --enable-libstdcxx-allocator=malloc
+#../gcc/configure --target=zpu-elf --prefix=/usr/local/zpu --enable-languages=c --with-gnu-as --with-gnu-ld --with-newlib --disable-shared --enable-newlib -v --enable-checking=misc,tree,rtl,rtlflag,gc,gcac,fold  --disable-multilib --disable-threads --enable-sjlj-exceptions --enable-libstdcxx-allocator=malloc
+#gmake
+#gmake install
 
