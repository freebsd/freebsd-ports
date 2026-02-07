--- install.sh.orig	2024-03-09 07:16:05 UTC
+++ install.sh
@@ -73,10 +73,10 @@ ln -s cowsay $PREFIX/bin/cowthink
 $usethisperl -p install.pl cowsay > $PREFIX/bin/cowsay
 chmod a+x $PREFIX/bin/cowsay
 ln -s cowsay $PREFIX/bin/cowthink
-mkdir -p $PREFIX/man/man1 || ($mkdir $PREFIX; mkdir $PREFIX/man; mkdir $PREFIX/man/man1)
-$usethisperl -p install.pl cowsay.1 > $PREFIX/man/man1/cowsay.1
-chmod a+r $PREFIX/man/man1/cowsay.1
-ln -s cowsay.1 $PREFIX/man/man1/cowthink.1
+mkdir -p $PREFIX/share/man/man1 || ($mkdir $PREFIX; mkdir $PREFIX/man; mkdir $PREFIX/man/man1)
+$usethisperl -p install.pl cowsay.1 > $PREFIX/share/man/man1/cowsay.1
+chmod a+r $PREFIX/share/man/man1/cowsay.1
+ln -s cowsay.1 $PREFIX/share/man/man1/cowthink.1
 mkdir -p $PREFIX/share/cows || (mkdir $PREFIX; mkdir $PREFIX/share; mkdir $PREFIX/share/cows)
 tar -cf - $filelist | (cd $PREFIX/share && tar -xvf -)
 set +x
