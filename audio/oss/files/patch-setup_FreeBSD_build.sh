--- setup/FreeBSD/build.sh.orig	2014-02-14 22:59:55 UTC
+++ setup/FreeBSD/build.sh
@@ -7,7 +7,7 @@ then
    TXT2MAN=$SRCDIR/setup/txt2man
 else
    echo "No gawk found. Using lesser replacement" >&2
-   cc -o txt2man origdir/setup/txt2man.c
+   $CC -o txt2man origdir/setup/txt2man.c
    TXT2MAN=./txt2man
 fi
 
@@ -38,7 +38,7 @@ echo "OSSLIBDIR=$OSSLIBDIR" > prototype/
 
 # Regenerating the config file templates
 rm -f /tmp/confgen
-if ! cc -o /tmp/confgen ./setup/FreeBSD/confgen.c
+if ! $CC -o /tmp/confgen ./setup/FreeBSD/confgen.c
 then
         echo Building confgen failed
         exit 1
@@ -146,7 +146,7 @@ cp .version prototype/$OSSLIBDIR/version
 # Licensing stuff
 if test -f $SRCDIR/4front-private/osslic.c
 then
-	cc -o prototype/usr/sbin/osslic -Isetup -Ikernel/nonfree/include -Ikernel/framework/include -Iinclude -Ikernel/OS/FreeBSD -I$SRCDIR $SRCDIR/4front-private/osslic.c
+	$CC -o prototype/usr/sbin/osslic -Isetup -Ikernel/nonfree/include -Ikernel/framework/include -Iinclude -Ikernel/OS/FreeBSD -I$SRCDIR $SRCDIR/4front-private/osslic.c
 	strip prototype/usr/sbin/osslic
 
         BITS=3 # Default to 32 bit ELF format
@@ -162,7 +162,7 @@ fi
 if test -f 4front-private/ossupdate.c
 then
   #ossupdate
-  cc -I. 4front-private/ossupdate.c -s -o prototype/usr/sbin/ossupdate
+  $CC -I. 4front-private/ossupdate.c -s -o prototype/usr/sbin/ossupdate
 fi
 
 sh $SRCDIR/setup/build_common.sh $SRCDIR $OSSLIBDIR
