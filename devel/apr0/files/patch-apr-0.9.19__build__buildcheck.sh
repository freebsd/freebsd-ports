--- ./apr-0.9.19/build/buildcheck.sh.orig	2004-11-24 23:10:04.000000000 +0000
+++ ./apr-0.9.19/build/buildcheck.sh	2010-10-20 21:08:11.853623919 +0000
@@ -26,7 +26,7 @@
 # output is multiline from 1.5 onwards
 
 # Require libtool 1.3.3 or newer
-libtool=`build/PrintPath glibtool libtool`
+libtool=${LIBTOOL}
 lt_pversion=`$libtool --version 2>/dev/null|sed -e 's/([^)]*)//g;s/^[^0-9]*//;s/[- ].*//g;q'`
 if test -z "$lt_pversion"; then
 echo "buildconf: libtool not found."
