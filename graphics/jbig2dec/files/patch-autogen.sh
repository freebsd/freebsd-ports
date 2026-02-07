--- autogen.sh.orig	2019-10-02 12:52:19 UTC
+++ autogen.sh
@@ -169,12 +169,3 @@ $AUTOMAKE --add-missing --copy $AUTOMAKE
 
 echo "  autoconf"
 autoconf
-
-if test -z "$*"; then
-        echo "I am going to run ./configure with no arguments - if you wish "
-        echo "to pass any to it, please specify them on the $0 command line."
-else
-	echo "running ./configure $@"
-fi
-
-$srcdir/configure "$@" && echo
