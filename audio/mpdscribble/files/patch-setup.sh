--- setup.sh.orig	2008-06-01 19:53:53.000000000 +0800
+++ setup.sh	2008-06-01 19:54:16.000000000 +0800
@@ -26,7 +26,7 @@
 echo 
 echo "press ctrl-c to cancel if this is not intended."
 echo "continue..."
-read -s
+read
 
 mkdir -p $CONF_DIR
 mkdir -p $CACHE_DIR
@@ -35,7 +35,7 @@
 echo -n "Please enter your audioscrobbler username: "
 read -e USERNAME
 echo -n "and password: "
-read -s -e PASSWORD
+read -e PASSWORD
 
 echo "username = $USERNAME" > $LOGIN
 chmod 600 $LOGIN
