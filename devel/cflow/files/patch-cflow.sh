--- cflow.sh.orig	Sun Feb 19 12:59:18 1995
+++ cflow.sh	Wed Jun  3 16:03:01 1998
@@ -1,41 +1,38 @@
-#! @CFLOW_SHELL@
+#!/bin/sh -
 
 # cflow - print a function call hierarchy
 # This script is contributed to the public domain by Andrew Moore
 # of Talke Studio.
 
-# exit on errors..
+: ${F2C:=f2c}
+: ${LEX:=flex}
+: ${YACC:="bison -y"}
+: ${CC:=gcc}
+: ${CPP:="$CC -E"}
+: ${PRCC:=/usr/local/bin/prcc}
+: ${PRCG:=/usr/local/bin/prcg}
+: ${RM:=/bin/rm}
 
-# this values can be overriden by devining them in the
-# enviornment
-F2C=${F2C:=f2c}
-LEX=${LEX:=flex}
-YACC={YACC:="bison -y"}
-CC=${CC:=gcc}
-CPP=${CPP:="$CC -E"}
-PRCC=${PRCC:=@PRCC@}
-PRCG=${PRCG:=@PRCG@}
 TMPFILE=/tmp/cflow.$$
 
 
-function prcc {
+prcc () {
 	if [ $verbose ]; then
 		echo $PRCC $* >/dev/tty
 	fi
-		
-	command $PRCC $*
+	$PRCC $*
 }
 
-function prcg {
+prcg () {
 
 	if [ $verbose ]; then
 		echo $PRCG $* >/dev/tty
 	fi
-	command $PRCG $*
+	$PRCG $*
 }
 
-function echo {
-	builtin echo -e "$*" 
+echo () {
+	printf "$*\n" 
 }
 
 
@@ -50,8 +47,7 @@
 
 progname=$0
 
-function usage
-{
+usage () {
 	echo $progname [-AaginPXVvxh] [-d n] [-w n] [-r name] [cpp-opts] files
 	echo "\t-a\tprint a seperate cal graph for each function"
 	echo "\t-A\teliminate ansi keywords"
@@ -86,8 +82,7 @@
 	exclude_directory="$exclude_directory".$$
 fi
 
-function do_mkdir 
-{
+do_mkdir () {
 	for i in $*
 	do
 		mkdir -p $i
@@ -98,27 +93,24 @@
 	done
 }
 
-function remove_exclude_files
-{
+remove_exclude_files () {
 	if [ -d $exclude_directory ]; then
-		rm -rf $exclude_directory
+		$RM -rf $exclude_directory
 	fi
 } 
 
 
-function remove_tmp_file
-{
+remove_tmp_file () {
 	if [ "$save_temps" ] ; then
 		echo temp file in  $TMPFILE
 	else
-		rm $TMPFILE
+		$RM $TMPFILE
 	fi
 }
 
-# call this once when we get are include files
+# call this once when we get our include files
 # called only if we want to exclude files
-function exclude 
-{
+exclude () {
 	if [ "$exclude_files" ]; then
 		do_mkdir $exclude_directory
 	fi
@@ -136,12 +128,9 @@
 	done		
 }
 
-#builtin -d echo 	# use gnu echo
 
 #  echo command line is $* >& 2
 while getopts aghsAPD:I:X:nU:d:ir:Vvw:x c; do
-#	echo option is $c
-#	echo OPTARG = $OPTARG
 	case $c in
 	D)
 		CPP="$CPP -D$OPTARG"
@@ -202,44 +191,48 @@
 	esac
 done
 
+shift $(expr $OPTIND - 1)
+
+if [ $# -eq 0 ]; then
+	usage
+fi
+
 if [ "$exclude_files" ]; then
 	exclude
 	CPP="$CPP -I$exclude_directory" 
 
 fi
 
-
-
-
-let count=$OPTIND-1
-shift $count
-unset count
-
-if [ $# -eq 0 ]; then
-	usage
+cat >${TMPFILE}.c <<\EOF
+#ifdef __GNUC__
+  yes;
+#endif
+EOF
+if  ${CPP} ${TMPFILE}.c | egrep yes >/dev/null 2>&1; then
+        CPP="${CPP} -D__attribute__(x)="
 fi
+$RM -f ${TMPFILE}.c
 
-for c in $*
-do
+for c in $*; do
 	case $c in
 	*.c|*.cc|*.C)
 		cname=$c
 		;;
 	*.f)
-		cname=`basename $c .f`.c
+		cname=$(basename $c .f).c
 		cat $c | $F2C >$cname
 		;;
 	*.F)
-		cname=`basename $c .F`.C
+		cname=$(basename $c .F).C
 		cat $c | $F2C >$cname
 		;;
 	*.l)
-		cname=`basename $c .l`.c
+		cname=$(basename $c .l).c
 		$LEX $c
 		sed '/# line/d' lex.yy.c >$cname
 		;;
 	*.y)
-		cname=`basename $c .y`.c
+		cname=$(basename $c .y).c
 		$YACC $c
 		sed '/# line/d' y.tab.c >$cname
 		;;
@@ -267,6 +260,7 @@
 
 	$CPP $cname  >>$TMPFILE
 done
+
 
 if [ "$no_prcg" ]; then
 	PRCG=cat
