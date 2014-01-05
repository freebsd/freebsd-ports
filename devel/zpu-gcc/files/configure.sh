set -e
rm -rf build
mkdir build
cd build
../binutils/configure --target=zpu-elf --prefix=/usr/local
#gmake
#gmake install
cd ..

export PATH=/usr/local/zpu/bin:$PATH
rm -rf gccbuild
mkdir gccbuild
cd gccbuild
../gcc/configure --target=zpu-elf --prefix=/usr/local --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --disable-shared --enable-newlib -v --enable-checking=misc,tree,rtl,rtlflag,gc,gcac,fold  --disable-multilib --disable-threads --enable-sjlj-exceptions --enable-libstdcxx-allocator=malloc
../gcc/configure --target=zpu-elf --prefix=`pwd`/../install --enable-languages=c --with-gnu-as --with-gnu-ld --with-newlib --disable-shared --enable-newlib -v --enable-checking=misc,tree,rtl,rtlflag,gc,gcac,fold  --disable-multilib --disable-threads --enable-sjlj-exceptions --enable-libstdcxx-allocator=malloc
#gmake
#gmake install

