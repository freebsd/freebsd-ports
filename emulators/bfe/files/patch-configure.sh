--- configure.sh.orig	Sat Jan 25 07:08:39 2003
+++ configure.sh	Thu Feb  6 02:11:55 2003
@@ -1,26 +1,18 @@
-#!/bin/bash
-
-# csh and tcsh do not like this file
-# ash produces incorrect quoting
-
-if [ "`/bin/ls -la /bin/sh |grep '\-> ash'`" != "" ]; then
-	echo -e "\nash shell is not supported\n"
-	exit
-fi
+#!/bin/sh
 
 ##############################################################################
 
-CC="cc"
-LD="cc"
-CFLAGS="-O2 -Wall"
+CC=%%CC%%
+LD=%%CC%%
+CFLAGS=%%CFLAGS%%
 LFLAGS=""
 
 PROG="bfe2"
 OWNER="root"
-GROUP="root"
+GROUP="whell"
 
 # install directories
-PREFIX="/usr/local"
+PREFIX=%%PREFIX%%
 BIN="bin"
 SYSCONF="etc"
 
@@ -106,13 +98,6 @@
 	INCS="\`pkg-config --cflags gtk+-2.0\`"
 else
 	echo -e "\tInvalid GTK version [$GTK]"
-	exit
-fi
-
-if [ "$BOCHS" == "2.0" ]; then
-	BOCHSPATH="$BOCHSPATH -q"
-else
-	echo -e "\tInvalid Bochs version [$BOCHS]"
 	exit
 fi
 
