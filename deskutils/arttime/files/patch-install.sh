--- install.sh.orig	2022-12-06 05:41:43 UTC
+++ install.sh
@@ -142,9 +142,9 @@ function printdirerror {
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
@@ -162,8 +162,8 @@ installerdir="${0:a:h}"
 
 # Copy bin files
 cd $installerdir/bin
-cp arttime $bindir/arttime
-cp artprint $bindir/artprint
+cp arttime $DESTDIR$bindir/arttime
+cp artprint $DESTDIR$bindir/artprint
 
 # Copy share files
 cd $installerdir/share/arttime/textart
@@ -179,10 +179,10 @@ for ((i = 1; i <= $artfilearraysize; i++)); do
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
@@ -227,6 +227,8 @@ elif [[ $machine =~ ^Darwin.*$ ]]; then
     echo "[4mNote[0m: Notification settings on macOS are not fully in control of an application.\n      To check if you have desired notification settings, open following link.\n      https://github.com/poetaman/arttime/issues/11"
 fi
 
+echoti cnorm
+exit 0
 # Check if path to arttime excutable is on user's $PATH
 if [[ ":$PATH:" == *":$bindir:"* ]]; then
     echo "Installation complete!\nType 'arttime' and press Enter to start arttime."
