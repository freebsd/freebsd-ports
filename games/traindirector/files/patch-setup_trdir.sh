--- setup_trdir.sh.orig	Wed Feb 18 15:03:49 2004
+++ setup_trdir.sh	Wed Feb 18 15:10:49 2004
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
@@ -37,7 +37,7 @@
 
 case $CHOIX in
     "2") FLNAME=".traindir.it"
-         echo " Avette schelto Italiano"
+         echo "Avete scelto l'italiano"
          STRING='locale .it';;
 	 	 
     "3") FLNAME=".traindir.fr"
@@ -54,9 +54,7 @@
     cp -f $SAMPLE/traindir/locales/$FLNAME $HOME/.traindir/
 fi
 
-cp -f $SAMPLE/traindir/* $TDHOMEDIR
-cp -f $SAMPLE/traindir/tdicons/*.*  $ICONDIR 
-
+cp -f -R $SAMPLE/traindir/* $TDHOMEDIR
 
 echo
 echo   "Creating startup script......"
@@ -64,11 +62,13 @@
 echo   "#!/bin/sh" > $HOME/traindir.sh
 echo   "# Startup file for traindirector" >> $HOME/traindir.sh
 echo   "#" >> $HOME/sstart-traindir
-echo   "TDHOME=\"$HOME/traindir\"" >> $HOME/traindir.sh
+echo   "TDHOME=\"$HOME/.traindir\"" >> $HOME/traindir.sh
 echo   "export TDHOME" >> $HOME/traindir.sh
 echo   "echo starting Traindirector" >> $HOME/traindir.sh
 echo   "$TRAINDIR/traindir" >> $HOME/traindir.sh
 
 chmod 0775 $HOME/traindir.sh
 echo "Installation complete"
-echo "You can run ~/traindir.sh from a X console"
\ No newline at end of file
+echo "a script file 'traindir.sh' has been created in the current"
+echo "directory. You can launch it to start the simulation, or move it"
+echo "to your user's bin directory if you want."
