--- ./kmail/avscripts/kmail_clamav.sh.orig	2008-01-15 04:57:51.000000000 +0300
+++ ./kmail/avscripts/kmail_clamav.sh	2010-03-27 01:28:30.548465474 +0300
@@ -35,7 +35,7 @@
 cat > $TEMPFILE
 
 # check for a running daemon
-if [ "`ps -eo comm|grep clamd`" = "clamd" ]; then
+if [ "`ps -axo comm|grep clamd`" = "clamd" ]; then
     chmod a+r $TEMPFILE
     CLAMCOMANDO="clamdscan --stdout --no-summary "
 else
