--- setup_trdir.sh.orig	Thu Sep 19 17:28:00 2002
+++ setup_trdir.sh	Mon Sep  8 12:50:55 2003
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
@@ -16,25 +16,29 @@
 echo
 echo  "Making traindir samples directory....."
 echo 
-TDHOMEDIR="$HOME/traindir"
-ICONDIR="$HOME/traindir/tdicons"
+TDHOMEDIR="$HOME/.traindir"
+ICONDIR="$HOME/.traindir/tdicons"
 
 mkdir $TDHOMEDIR
 mkdir $ICONDIR
 
-cp $SAMPLE/traindir/* $TDHOMEDIR
-cp $SAMPLE/traindir/tdicons/*.*  $ICONDIR
+#little hack. It works anyway.
+cp -R $SAMPLE/traindir/* $TDHOMEDIR
+#cp $SAMPLE/traindir/tdicons/*.*  $ICONDIR
 echo
 echo   "Creating start-traindir script......"
 echo
 echo   "#!/bin/sh" > start-traindir
 echo   "# Startup file for traindirector" >> start-traindir
 echo   "#" >> start-traindir
-echo   "TDHOME=\"$HOME/traindir\"" >> start-traindir
+echo   "TDHOME=\"$HOME/.traindir\"" >> start-traindir
 echo   "export TDHOME" >> start-traindir
 echo   "echo starting Traindirector" >> start-traindir
 echo   "$TRAINDIR/traindir" >> start-traindir
 
 chmod 0775 start-traindir
 echo "Installation complete"
-echo "You can run ~/start-traindir in a X console"
\ No newline at end of file
+#echo "You can run ./start-traindir in a X console"
+echo "a script file 'start-traindir' has been created in the current"
+echo "directory. You can launch it to start the simulation, or move it"
+echo "to your user's bin directory if you want."
