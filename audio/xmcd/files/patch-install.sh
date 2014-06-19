--- install.sh.orig	2004-04-21 19:27:01.000000000 +0000
+++ install.sh
@@ -625,7 +625,7 @@ if [ "$OS_SYS" = A/UX ]
 then
 	# Apple A/UX
 	SHELL=/bin/ksh
-elif [ "$OS_SYS" = FreeBSD ]
+elif [ "$OS_SYS" = FreeBSD -o "$OS_SYS" = DragonFly ]
 then
 	# FreeBSD
 	OS_REL_T=`echo "$OS_REL_T" | sed 's/\..*$//'`
@@ -1170,7 +1170,7 @@ make_dir $ARCHBIN $DIRPERM $OWNER $GROUP
 make_dir $ARCHLIB $DIRPERM $OWNER $GROUP
 make_dir $DISCOGDIR $GDIRPERM $OWNER $GROUP
 
-if [ -n "$MANDIR" ]
+if [ -n "$MANDIR" -a ! -d "$MANDIR" ]
 then
 	make_dir $MANDIR $DIRPERM $OWNER $GROUP
 fi
