$FreeBSD$

--- ../../j2se/src/solaris/bin/java-rmi.cgi.sh.orig	Sun Jul 29 23:03:30 2007
+++ ../../j2se/src/solaris/bin/java-rmi.cgi.sh	Sun Jul 29 23:03:30 2007
@@ -32,7 +32,7 @@
 #
 # PATH=/home/peter/java/bin:$PATH
 #
-PATH=/usr/local/java/bin:$PATH
+PATH=%%LOCALBASE%%/java/bin:$PATH
 exec java \
 	-DAUTH_TYPE="$AUTH_TYPE" \
 	-DCONTENT_LENGTH="$CONTENT_LENGTH" \
