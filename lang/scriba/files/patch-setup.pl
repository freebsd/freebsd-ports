--- setup.pl.orig	Wed Mar  2 19:06:18 2005
+++ setup.pl	Wed Mar  2 19:08:02 2005
@@ -176,7 +176,6 @@
 #
 $esdlocation = undef;
 for (@INC){
-  next if /\./;
   if( -e "$_/jamal/esd.pm" ){
     $esdlocation = "$_/jamal/esd.pm";
     }
@@ -1152,7 +1151,7 @@
   let ERRCOUNT = \$ERRCOUNT+1
 fi         
 
-chown $owner:$owner $to 2>/dev/null
+chown $owner $to 2>/dev/null
 if [ \$? -ne 0 ] ; then
   echo "###ERROR setting the owner of the file $to to $owner"
   let ERRCOUNT = \$ERRCOUNT+1
@@ -1186,7 +1185,7 @@
   let ERRCOUNT = \$ERRCOUNT+1
 fi  
 
-chown $owner:$owner $tofils 2>/dev/null
+chown $owner $tofils 2>/dev/null
 if [ \$? -ne 0 ] ; then
   echo "###ERROR setting the owner of the file $tofils to $owner"
   let ERRCOUNT = \$ERRCOUNT+1
@@ -1410,7 +1409,7 @@
   print F <<ENDSHELL;
 #!/bin/sh
 #
-# Start/stops the ScriptBasic httpd daemon (/usr/bin/sbhttpd)
+# Start/stops the ScriptBasic httpd daemon (%%PREFIX%%/bin/sbhttpd)
 #
 
 PIDFILE=$LOG/pid.txt
@@ -1453,7 +1452,7 @@
 			echo "\$0 \$ARG: sbhttpd (pid \$PID) already running"
 			continue
 		fi
-		if /usr/bin/sbhttpd -start ; then
+		if %%PREFIX%%/bin/sbhttpd -start ; then
 		    echo "\$0 \$ARG: sbhttpd started"
 		else
 		    echo "\$0 \$ARG: sbhttpd could not be started"
@@ -1795,17 +1794,17 @@
 #
 # UNIX installation default configuration values
 #
-$INSTALL_DEFAULT_CONFIGDIR='/etc/scriba';
-$INSTALL_DEFAULT_INCLUDE  ='/usr/share/scriba/include';
-$INSTALL_DEFAULT_SOURCE   ='/usr/share/scriba/source';
-$INSTALL_DEFAULT_MODULE   ='/usr/local/lib/scriba';
-$INSTALL_DEFAULT_DOCU     ='/usr/share/scriba/source';
-$INSTALL_DEFAULT_LIB      ='/usr/local/lib';
-$INSTALL_DEFAULT_CACHE    ='/var/cache/scriba/cache';
-$INSTALL_DEFAULT_HEBTEMP  ='/var/cache/scriba/hebtemp';
-$INSTALL_DEFAULT_BIN      ='/usr/bin';
-$INSTALL_DEFAULT_LOG      ='/var/log/scriba';
-$INSTALL_DEFAULT_ETC      ='/etc/init.d';
+$INSTALL_DEFAULT_CONFIGDIR='%%PREFIX%%/etc/scriba';
+$INSTALL_DEFAULT_INCLUDE  ='%%PREFIX%%/include/scriba';
+$INSTALL_DEFAULT_SOURCE   ='%%DATADIR%%/source';
+$INSTALL_DEFAULT_MODULE   ='%%PREFIX%%/lib/scriba';
+$INSTALL_DEFAULT_DOCU     ='%%DOCSDIR%%';
+$INSTALL_DEFAULT_LIB      ='%%PREFIX%%/lib';
+$INSTALL_DEFAULT_CACHE    ='%%PREFIX%%/var/cache/scriba/cache';
+$INSTALL_DEFAULT_HEBTEMP  ='%%PREFIX%%/var/cache/scriba/hebtemp';
+$INSTALL_DEFAULT_BIN      ='%%PREFIX%%/bin';
+$INSTALL_DEFAULT_LOG      ='%%PREFIX%%/var/log/scriba';
+$INSTALL_DEFAULT_ETC      ='%%PREFIX%%/etc/rc.d';
 
 %INSTALL_DEFAULT = (
 '--install-configdir' => $INSTALL_DEFAULT_CONFIGDIR,
