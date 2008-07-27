--- setup.sh.orig	2005-04-17 16:53:46.000000000 +0200
+++ setup.sh	2008-07-22 02:30:33.000000000 +0200
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-if [ $UID = "0" ]; then 
+if [ $(id -u) -eq 0 ]; then 
   echo "user root, system-wide installation assumed."
   echo
   CONF_DIR=/etc
@@ -25,8 +25,8 @@
 echo "log file:            $LOG"
 echo 
 echo "press ctrl-c to cancel if this is not intended."
-echo "continue..."
-read -s
+echo "press enter to continue..."
+read junk
 
 mkdir -p $CONF_DIR
 mkdir -p $CACHE_DIR
@@ -35,17 +35,19 @@
 echo -n "Please enter your audioscrobbler username: "
 read -e USERNAME
 echo -n "and password: "
-read -s -e PASSWORD
+read -e PASSWORD
 
 echo "username = $USERNAME" > $LOGIN
 chmod 600 $LOGIN
-MD5=`echo -n $PASSWORD | md5sum | awk '{print $1}'`
+MD5=$(echo -n $PASSWORD | md5 -q)
 echo "password = $MD5" >> $LOGIN
 
 echo "cache = $CACHE" >> $LOGIN
 echo "log = $LOG" >> $LOGIN
 echo "verbose = 2" >> $LOGIN
 
+touch $CACHE
+
 echo ""
 echo "Thank you."
 echo "You can try running mpdscribble now."
