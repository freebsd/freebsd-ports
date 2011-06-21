--- setup/setupdir.sh.orig	2011-01-04 20:33:08.000000000 -0500
+++ setup/setupdir.sh	2011-06-21 19:09:44.000000000 -0400
@@ -84,7 +84,9 @@ echo BLDDIR=$BLDDIR > .directories
 echo SRCDIR=$SRCDIR >> .directories
 echo OSSLIBDIR=$OSSLIBDIR >> .directories
 
-cc -o dirsetup $SRCDIR/setup/dirsetup.c
+CC=${CC:-cc}
+
+$CC -o dirsetup $SRCDIR/setup/dirsetup.c
 
 # Make sure the latest soundcard.h version is installed in the system
 #rm /usr/include/sys/soundcard.h
@@ -142,7 +144,7 @@ then
   DTARGETOS="-D$TARGETOS"
 fi
 
-cc -D`uname -s` $DTARGETOS -o srcconf $SRCDIR/setup/srcconf.c
+$CC -D`uname -s` $DTARGETOS -o srcconf $SRCDIR/setup/srcconf.c
 
 if ./srcconf $*
 then
@@ -245,7 +247,7 @@ fi
 # Setup the link to the right os.h file for this operating system.
 (cd kernel/framework/include;ln -s ../../../kernel/OS/$OS/os_*.h os.h)
 
-cc -o ossvers -I./kernel/framework/include  setup/ossvers.c
+$CC -o ossvers -I./kernel/framework/include  setup/ossvers.c
 ./ossvers > .version
 rm ./ossvers
 
