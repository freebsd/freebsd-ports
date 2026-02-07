--- autobackupmysql.sh.orig	2009-12-18 13:23:34.000000000 +0100
+++ autobackupmysql.sh	2011-12-13 13:18:11.000000000 +0100
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/usr/local/bin/bash
 #
 # Automatic MySQL Backup Script
 # VER. 1.1 - http://sourceforge.net/projects/autobackupmysql/
@@ -292,6 +292,7 @@
 LOGERR=$BACKUPDIR/ERRORS_$DBHOST-`date +%N`.log		# Logfile Name
 BACKUPFILES=""
 OPT="--quote-names --opt"			# OPT string for use with mysqldump ( see man mysqldump )
+UNAME_S="`uname -s | tr "[:upper:]" "[:lower:]"`"	# identify operating system
 
 # Add --compress mysqldump option to $OPT
 if [ "$COMMCOMP" = "yes" ];
@@ -440,7 +441,8 @@
 	# If DBs are excluded
 	for exclude in $DBEXCLUDE
 	do
-		DBNAMES=`echo $DBNAMES | sed "s/\b$exclude\b//g"`
+		[ "$UNAME_S" = "linux" ] && DBNAMES=`echo $DBNAMES | sed "s/\b$exclude\b//g"`
+		[ "$UNAME_S" = "freebsd" ] && DBNAMES=`echo $DBNAMES | sed "s/[[:<:]]$exclude[[:>:]]//g"`
 	done
 
         MDBNAMES=$DBNAMES
