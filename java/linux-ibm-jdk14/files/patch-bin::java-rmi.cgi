$FreeBSD$

--- bin/java-rmi.cgi.orig	Tue Nov 19 15:43:50 2002
+++ bin/java-rmi.cgi	Tue Nov 19 15:52:51 2002
@@ -45,7 +45,7 @@
 #
 # PATH=/home/peter/java/bin:$PATH
 #
-PATH=/usr/local/java/bin:$PATH
+PATH=%%APP_HOME%%/bin:$PATH
 exec java \
 	-DAUTH_TYPE="$AUTH_TYPE" \
 	-DCONTENT_LENGTH="$CONTENT_LENGTH" \
