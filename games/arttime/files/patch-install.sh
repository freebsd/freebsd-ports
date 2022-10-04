--- install.sh.orig	2022-09-24 00:11:14 UTC
+++ install.sh
@@ -119,9 +119,9 @@ function printdirerror {
     fi
 }
 
-installdircode=$(checkdir $installdir)
-bindircode=$(checkdir $bindir)
-artdircode=$(checkdir $artdir)
+installdircode=$(checkdir $DESTDIR$installdir)
+bindircode=$(checkdir $DESTDIR$bindir)
+artdircode=$(checkdir $DESTDIR$artdir)
 
 printdirerror $installdircode $installdir
 printdirerror $bindircode $bindir
@@ -139,8 +139,8 @@ installerdir="${0:a:h}"
 
 # Copy bin files
 cd $installerdir/bin
-cp arttime $bindir/arttime
-cp artprint $bindir/artprint
+cp arttime $DESTDIR$bindir/arttime
+cp artprint $DESTDIR$bindir/artprint
 
 # Copy share files
 cd $installerdir/share/arttime/textart
@@ -156,10 +156,10 @@ for ((i = 1; i <= $artfilearraysize; i++)); do
         oldmessage='"Custom message for art goes here"'
         oldmessage="$(head -n1 $artdir/$file)"
         newart="$(tail -n +2 $file)"
-        printf '%s\n' "$oldmessage" >$artdir/$file
-        printf '%s\n' "$newart" >>$artdir/$file
+        printf '%s\n' "$oldmessage" >$DESTDIR$artdir/$file
+        printf '%s\n' "$newart" >>$DESTDIR$artdir/$file
     else
-        cp $file $artdir/$file
+        cp $file $DESTDIR$artdir/$file
     fi
     percentdone=$(((i-1.0)/(artfilearraysize-1.0)*100.0))
     [[ $percentdone -lt 1 ]] && percentdone="0"
@@ -191,3 +191,5 @@ else
     fi
 fi
 tput cnorm
+
+exit 0
