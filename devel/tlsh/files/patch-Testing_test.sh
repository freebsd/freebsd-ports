--- Testing/test.sh.orig	2020-12-10 01:30:11 UTC
+++ Testing/test.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 ##################################
 # set CREATE_EXP_FILE=1 if you want this script to create the Expected Results for the regression tests
@@ -8,7 +8,7 @@ CREATE_EXP_FILE=0
 echoerr() { echo "$@" 1>&2; }
 
 BASEDIR=$(dirname $0)
-pushd $BASEDIR > /dev/null
+cd $BASEDIR
 
 LISTOPTION=1
 JSONOPTION=1
@@ -34,14 +34,12 @@ echo "TLSH_PROG=$TLSH_PROG"
 if test ! -f $TLSH_PROG
 then
 	echoerr "error: (127), you must compile $TLSH_PROG"
-        popd > /dev/null
 	exit 127
 fi
 
 if test ! -f $SIMP_PROG
 then
 	echoerr "error: (127), you must compile $SIMP_PROG"
-        popd > /dev/null
 	exit 127
 fi
 
@@ -104,7 +102,6 @@ runit() {
 	if test ! -f $TMP/example_data.out
 	then
 		echoerr "error: (1), $TMP/example_data.out does not exist"
-		popd > /dev/null
 		exit 1
 	fi
 	EXPECTED_OUT=exp/example_data.$HASH.$CHKSUM.$XLEN.out_EXP
@@ -114,7 +111,6 @@ runit() {
 		if test $CREATE_EXP_FILE = 0
 		then
 			echoerr "error: (1), Expected Result file $EXPECTED_OUT does not exist"
-			popd > /dev/null
 			exit 1
 		else
 			echo "cp $TMP/example_data.out $EXPECTED_OUT"
@@ -126,7 +122,6 @@ runit() {
 		if test $CREATE_EXP_FILE = 0
 		then
 			echoerr "error: (1), Expected Result file $EXPECTED_ERR does not exist"
-			popd > /dev/null
 			exit 1
 		else
 			echo "cp $TMP/example_data.err $EXPECTED_ERR"
@@ -137,7 +132,6 @@ runit() {
 	if test ! $diffc = 0
 	then
 		echoerr "error: (1), diff $TMP/example_data.out $EXPECTED_OUT"
-		popd > /dev/null
 		exit 1
 	fi
 
@@ -145,7 +139,6 @@ runit() {
 	if test ! $diffc = 0
 	then
 		echoerr "error: (1), diff $TMP/example_data.err $EXPECTED_ERR"
-		popd > /dev/null
 		exit 1
 	fi
 
@@ -160,7 +153,6 @@ runit() {
 		if test ! $diffc = 0
 		then
 			echoerr "error: (1), diff $TMP/example_data.json_out $EXPECTED_OUT"
-			popd > /dev/null
 			exit 1
 		fi
 		echo "passed"
@@ -194,7 +186,6 @@ runit() {
 		if test $CREATE_EXP_FILE = 0
 		then
 			echoerr "error: (1), Expected Result file $EXPECTED_SCO does not exist"
-			popd > /dev/null
 			exit 1
 		else
 			echo "cp $TMP/example_data.scores $EXPECTED_SCO"
@@ -206,7 +197,6 @@ runit() {
 		if test $CREATE_EXP_FILE = 0
 		then
 			echoerr "error: (1), Expected Result file $EXPECTED_ERR does not exist"
-			popd > /dev/null
 			exit 1
 		else
 			echo "cp $TMP/example_data.err2 $EXPECTED_ERR"
@@ -218,14 +208,12 @@ runit() {
 	if test ! $diffc = 0
 	then
 		echoerr "error: (2), diff $TMP/example_data.scores $EXPECTED_SCO"
-		popd > /dev/null
 		exit 2
 	fi
 	diffc=`diff --ignore-all-space $TMP/example_data.err2 $EXPECTED_ERR | wc -l`
 	if test ! $diffc = 0
 	then
 		echoerr "error: (2), diff $TMP/example_data.err2 $EXPECTED_ERR"
-		popd > /dev/null
 		exit 2
 	fi
 
@@ -260,7 +248,6 @@ runit() {
 			if test $CREATE_EXP_FILE = 0
 			then
 				echoerr "error: (3), Expected Result file $EXPECTED_SCO does not exist"
-				popd > /dev/null
 				exit 1
 			else
 				echo "cp $TMP/example_data.scores.2 $EXPECTED_SCO"
@@ -272,7 +259,6 @@ runit() {
 		if test ! $diffc = 0
 		then
 			echoerr "error: (3) diff $TMP/example_data.scores.2 $EXPECTED_SCO"
-			popd > /dev/null
 			exit 3
 		fi
 
@@ -304,7 +290,6 @@ runit() {
 		if test $CREATE_EXP_FILE = 0
 		then
 			echoerr "error: ($testnum), Expected Result file $EXPECTED_SCO does not exist"
-			popd > /dev/null
 			exit 1
 		else
 			echo "cp $TMP/example_data.xref.scores $EXPECTED_SCO"
@@ -315,7 +300,6 @@ runit() {
 	diff --ignore-all-space $TMP/example_data.xref.scores $EXPECTED_SCO > /dev/null 2>/dev/null
 	if [ $? -ne 0 ]; then
 		echoerr "error: ($testnum), diff $TMP/example_data.xref.scores $EXPECTED_SCO"
-		popd > /dev/null
 		exit $testnum
 	fi
 
@@ -334,7 +318,6 @@ runit() {
 		diff --ignore-all-space $TMP/example_data.xref.json_scores $EXPECTED_SCO > /dev/null 2>/dev/null
 		if [ $? -ne 0 ]; then
 			echoerr "error: ($testnum), diff $TMP/example_data.xref.json_scores $EXPECTED_SCO"
-			popd > /dev/null
 			exit $testnum
 		fi
 		echo "passed"
@@ -370,7 +353,6 @@ runit() {
 			if test $CREATE_EXP_FILE = 0
 			then
 				echoerr "error: ($testnum), Expected Result file $EXPECTED_SCO does not exist"
-				popd > /dev/null
 				exit 1
 			else
 				echo "cp $TMP/example_data.scores.2.T-201 $EXPECTED_SCO"
@@ -381,7 +363,6 @@ runit() {
 		diff --ignore-all-space $TMP/example_data.scores.2.T-201 $EXPECTED_SCO > /dev/null 2>/dev/null
 		if [ $? -ne 0 ]; then
 			echoerr "error: ($testnum) diff $TMP/example_data.scores.2.T-201 $EXPECTED_SCO"
-			popd > /dev/null
 			exit $testnum
 		fi
 		echo "passed"
@@ -398,7 +379,6 @@ runit
 if test "$1" = "_go"
 then
 	echo "passed all example data tests (for go implementation)"
-	popd > /dev/null
 	exit 0
 fi
 runit "-xlen"
@@ -428,7 +408,6 @@ then
 	if test $CREATE_EXP_FILE = 0
 	then
 		echoerr "error: ($testnum), Expected Result file $EXPECTED_TESTLEN does not exist"
-		popd > /dev/null
 		exit 1
 	else
 		echo "cp $TMP/testlen.out $EXPECTED_TESTLEN"
@@ -439,7 +418,6 @@ fi
 diff --ignore-all-space $TMP/testlen.out $EXPECTED_TESTLEN > /dev/null 2>/dev/null
 if [ $? -ne 0 ]; then
 	echoerr "error: ($testnum) diff $TMP/testlen.out $EXPECTED_TESTLEN"
-	popd > /dev/null
 	exit $testnum
 fi
 echo "passed"
@@ -467,7 +445,6 @@ for file in small small2 ; do
 		if test $CREATE_EXP_FILE = 0
 		then
 			echoerr "error: ($testnum), Expected Result file $EXPECTED_TLSH does not exist"
-			popd > /dev/null
 			exit 1
 		else
 			echo "cp $TMP/$file.tlsh $EXPECTED_TLSH"
@@ -478,7 +455,6 @@ for file in small small2 ; do
 	diff --ignore-all-space $TMP/$file.tlsh $EXPECTED_TLSH
 	if [ $? -ne 0 ]; then
 		echoerr "error: ($testnum) $TMP/$file.tlsh $EXPECTED_TLSH"
-		popd > /dev/null
 		exit $testnum
 	fi
 done
@@ -511,14 +487,12 @@ then
 	if test ! -f $EXPECTED_SCO
 	then
 		echoerr "error: ($testnum), Expected Result file $EXPECTED_SCO does not exist"
-		popd > /dev/null
 		exit 1
 	fi
 
 	diff --ignore-all-space $TMP/example_data.scores.l2.T-201 $EXPECTED_SCO > /dev/null 2>/dev/null
 	if [ $? -ne 0 ]; then
 		echoerr "error: ($testnum) diff $TMP/example_data.scores.l2.T-201 $EXPECTED_SCO"
-		popd > /dev/null
 		exit $testnum
 	fi
 
@@ -533,7 +507,6 @@ then
 	diff --ignore-all-space $TMP/example_data.scores.l2csv.T-201 $EXPECTED_SCO > /dev/null 2>/dev/null
 	if [ $? -ne 0 ]; then
 		echoerr "error: ($testnum) diff $TMP/example_data.scores.l2csv.T-201 $EXPECTED_SCO"
-		popd > /dev/null
 		exit $testnum
 	fi
 
@@ -563,14 +536,12 @@ then
 	if test ! -f $EXPECTED_RES
 	then
 		echoerr "error: ($testnum), Expected Result file $EXPECTED_RES does not exist"
-		popd > /dev/null
 		exit 1
 	fi
 
 	diff --ignore-all-space $TMP/example_data.Week3.split.tlsh $EXPECTED_RES > /dev/null 2>/dev/null
 	if [ $? -ne 0 ]; then
 		echoerr "error: ($testnum) diff $TMP/example_data.Week3.split.tlsh $EXPECTED_RES"
-		popd > /dev/null
 		exit $testnum
 	fi
 
@@ -598,7 +569,6 @@ then
 	if test $CREATE_EXP_FILE = 0
 	then
 		echoerr "error: ($testnum), Expected Result file $EXPECTED_STEST does not exist"
-		popd > /dev/null
 		exit 1
 	else
 		echo "cp $TMP/simple_unittest.out $EXPECTED_STEST"
@@ -609,13 +579,10 @@ fi
 diff --ignore-all-space $TMP/simple_unittest.out $EXPECTED_STEST > /dev/null 2>/dev/null
 if [ $? -ne 0 ]; then
 	echoerr "error: ($testnum) diff $TMP/simple_unittest.out $EXPECTED_STEST"
-        popd > /dev/null
-	exit -1
+	exit 255
 fi
 
 echo "passed all example data tests"
-
-popd > /dev/null
 
 echo
 echo "If you have made changes to the Tlsh python module, build and install it, and run python_test.sh"
