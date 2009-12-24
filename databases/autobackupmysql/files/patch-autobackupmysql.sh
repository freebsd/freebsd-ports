--- autobackupmysql.sh.orig	2009-12-21 15:25:29.000000000 +0100
+++ autobackupmysql.sh	2009-12-21 16:07:01.000000000 +0100
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/usr/local/bin/bash
 #
 # Automatic MySQL Backup Script
 # VER. 1.1 - http://sourceforge.net/projects/autobackupmysql/
@@ -30,8 +30,8 @@
 # Check configuration files
 if [ -f "autobackupmysql.conf" ] ; then
 	source "autobackupmysql.conf"
-elif [ - f "/etc/autobackupmysql.conf" ] ; then
-	source "/etc/autobackupmysql.conf"
+elif [ -f "/usr/local/etc/autobackupmysql.conf" ] ; then
+	source "/usr/local/etc/autobackupmysql.conf"
 else
 # Username to access the MySQL server e.g. dbuser
 USERNAME='dbuser'

