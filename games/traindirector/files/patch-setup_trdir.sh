--- setup_trdir.sh.orig	Tue Jan 25 13:44:55 2005
+++ setup_trdir.sh	Tue Jan 25 13:45:30 2005
@@ -6,9 +6,9 @@
 # edit the folowing line
 #
 # This is the place where traindirector is installed
-TRAINDIR="/usr/local/bin"
+TRAINDIR="PREFIX/bin"
 # This is the place where samples file is installed
-SAMPLE="/usr/local/share"
+SAMPLE="PREFIX/share"
 ##################################################################"
 echo "*********************************"
 echo "*  Traindirector Installation   *"
@@ -16,7 +16,7 @@
 echo
 echo  "Making traindir samples directory....."
 echo 
-TDHOMEDIR="$HOME/traindir"
+TDHOMEDIR="$HOME/.traindir"
 ICONDIR="$TDHOMEDIR/tdicons"
 LOCALEDIR="$TDHOMEDIR/locales"
 if ! test -d $TDHOMEDIR  ; then
@@ -38,7 +38,7 @@
 
 case $CHOIX in
     "2") FLNAME=".traindir.it"
-         echo " Avette schelto Italiano"
+         echo "Avete scelto l'italiano"
          STRING='locale .it';;
 	 	 
     "3") FLNAME=".traindir.fr"
@@ -56,12 +56,10 @@
 if ! test -d $HOME/.traindir ; then
     mkdir $HOME/.traindir
 fi
-    echo $STRING > $HOME/.traindir/.traindir.ini
-    cp -f $SAMPLE/traindir/locales/$FLNAME $HOME/.traindir/
-
-cp -f $SAMPLE/traindir/* $TDHOMEDIR
-cp -f $SAMPLE/traindir/tdicons/*.*  $ICONDIR 
+echo $STRING > $HOME/.traindir/.traindir.ini
+cp -f -R $SAMPLE/traindir/locales/$FLNAME $HOME/.traindir/
 
+cp -f -R $SAMPLE/traindir/* $TDHOMEDIR
 
 echo
 echo   "Creating startup script......"
@@ -69,12 +67,13 @@
 echo   "#!/bin/sh" > $HOME/traindir.sh
 echo   "# Startup file for traindirector" >> $HOME/traindir.sh
 echo   "#" >> $HOME/traindir.sh
-echo   "TDHOME=\"$HOME/traindir\"" >> $HOME/traindir.sh
+echo   "TDHOME=\"$HOME/.traindir\"" >> $HOME/traindir.sh
 echo   "export TDHOME" >> $HOME/traindir.sh
 echo   "echo starting Traindirector" >> $HOME/traindir.sh
 echo   "$TRAINDIR/traindir" >> $HOME/traindir.sh
 
 chmod 0775 $HOME/traindir.sh
 echo "Installation complete"
-echo "You can run ~/traindir.sh from a X console"
-
+echo "a script file 'traindir.sh' has been created in the current"
+echo "directory. You can launch it to start the simulation, or move it"
+echo "to your user's bin directory if you want."
