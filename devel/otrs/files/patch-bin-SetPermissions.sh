--- bin/SetPermissions.sh.orig	Fri Jul 21 21:03:43 2006
+++ bin/SetPermissions.sh	Fri Jul 21 21:07:02 2006
@@ -55,9 +55,10 @@
 echo "chown -R $WEBUSER:$OTRSGROUP $OTRSDEST"
 chown $WEBUSER:$OTRSGROUP $OTRSDEST
 chown -R $WEBUSER:$OTRSGROUP $OTRSDEST
-echo "chmod -R og+rw $OTRSDEST"
-chmod ug+wr $OTRSDEST
+echo "chmod -R og+rw $OTRSDEST/*"
 chmod -R ug+wr $OTRSDEST
+# procmail does not like the home directory to be group writeable
+chmod g-w $OTRSDEST
 
 # set the $HOME to the OTRS user
 echo "chown $OTRSUSER:$OTRSGROUP $OTRSDEST"
