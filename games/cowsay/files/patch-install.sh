--- install.sh.orig	Sat Nov 27 11:40:57 2004
+++ install.sh	Sat Nov 27 11:44:05 2004
@@ -76,7 +76,7 @@
 mkdir -p $PREFIX/man/man1 || ($mkdir $PREFIX; mkdir $PREFIX/man; mkdir $PREFIX/man/man1)
 $usethisperl -p install.pl cowsay.1 > $PREFIX/man/man1/cowsay.1
 chmod a+r $PREFIX/man/man1/cowsay.1
-ln -s cowsay.1 $PREFIX/man/man1/cowthink.1
+#ln -s cowsay.1 $PREFIX/man/man1/cowthink.1
 mkdir -p $PREFIX/share/cows || (mkdir $PREFIX; mkdir $PREFIX/share; mkdir $PREFIX/share/cows)
 tar -cf - $filelist | (cd $PREFIX/share && tar -xvf -)
 set +x
