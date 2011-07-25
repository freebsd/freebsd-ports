--- setup/FreeBSD/build.sh.orig	2011-01-04 20:33:08.000000000 -0500
+++ setup/FreeBSD/build.sh	2011-07-25 13:39:05.000000000 -0400
@@ -7,7 +7,7 @@
    TXT2MAN=$SRCDIR/setup/txt2man
 else
    echo "No gawk found. Using lesser replacement" >&2
-   cc -o txt2man origdir/setup/txt2man.c
+   $CC -o txt2man origdir/setup/txt2man.c
    TXT2MAN=./txt2man
 fi
 
@@ -38,7 +38,7 @@
 
 # Regenerating the config file templates
 rm -f /tmp/confgen
-if ! cc -o /tmp/confgen ./setup/FreeBSD/confgen.c
+if ! $CC -o /tmp/confgen ./setup/FreeBSD/confgen.c
 then
         echo Building confgen failed
         exit 1
@@ -146,7 +146,7 @@
 # Licensing stuff
 if test -f $SRCDIR/4front-private/osslic.c
 then
-	cc -o prototype/usr/sbin/osslic -Isetup -Ikernel/nonfree/include -Ikernel/framework/include -Iinclude -Ikernel/OS/FreeBSD -I$SRCDIR $SRCDIR/4front-private/osslic.c
+	$CC -o prototype/usr/sbin/osslic -Isetup -Ikernel/nonfree/include -Ikernel/framework/include -Iinclude -Ikernel/OS/FreeBSD -I$SRCDIR $SRCDIR/4front-private/osslic.c
 	strip prototype/usr/sbin/osslic
 
         BITS=3 # Default to 32 bit ELF format
@@ -162,7 +162,7 @@
 if test -f 4front-private/ossupdate.c
 then
   #ossupdate
-  cc -I. 4front-private/ossupdate.c -s -o prototype/usr/sbin/ossupdate
+  $CC -I. 4front-private/ossupdate.c -s -o prototype/usr/sbin/ossupdate
 fi
 
 sh $SRCDIR/setup/build_common.sh $SRCDIR $OSSLIBDIR
