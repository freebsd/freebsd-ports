--- gcc/gcc/fixinc/mkfixinc.sh.orig	2013-06-17 08:08:36.000000000 -0400
+++ gcc/gcc/fixinc/mkfixinc.sh	2013-06-17 08:08:54.000000000 -0400
@@ -72,7 +72,7 @@
 #  OK.  We gotta make the thing.
 #  make and install either the binary or the default script
 
-defs="SHELL=\"$SHELL\" CC=\"$CC\" CFLAGS=\"$CFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBERTY=\"$LIBERTY\""
+defs="SHELL=\"/bin/sh\" CC=\"$CC\" CFLAGS=\"$CFLAGS\" LDFLAGS=\"$LDFLAGS\" LIBERTY=\"$LIBERTY\""
 cmd="$MAKE ${defs} install-bin"
 echo $cmd
 eval $cmd
