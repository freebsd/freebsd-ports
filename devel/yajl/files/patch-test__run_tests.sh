--- ./test/run_tests.sh.orig	2010-01-08 18:05:11.000000000 +0100
+++ ./test/run_tests.sh	2010-03-29 19:19:09.218500262 +0200
@@ -1,7 +1,7 @@
-#!/usr/bin/env bash
+#!/bin/sh
 
 DIFF_FLAGS="-u"
-if [[ `uname` == *W32* ]] ; then
+if [ `uname` = "*W32*" ] ; then
   DIFF_FLAGS="-wu"
 fi
 
@@ -9,9 +9,9 @@
 # particular test binary (useful for non-cmake build systems).
 if [ -z "$testBin" ]; then
 	testBin="../build/test/Debug/yajl_test.exe"
-	if [[ ! -x $testBin ]] ; then
+	if [ ! -x $testBin ] ; then
 	  testBin="../build/test/yajl_test"
-	  if [[ ! -x $testBin ]] ; then
+	  if [  ! -x $testBin ] ; then
 	    echo "cannot execute test binary: '$testBin'"  
 	    exit 1;
 	  fi
@@ -20,41 +20,44 @@
 
 echo "using test binary: $testBin"
 
-let testsSucceeded=0
-let testsTotal=0 
+testsSucceeded=0
+testsTotal=0 
 
 for file in cases/*.json ; do
   allowComments="-c"
 
   # if the filename starts with dc_, we disallow comments for this test
-  if [[ $(basename $file) == dc_* ]] ; then
-    allowComments=""
-  fi
+  case $(basename $file) in
+    dc_*)
+      allowComments=""
+    ;;
+  esac
   echo -n " test case: '$file': "
-  let iter=1
+  iter=1
   success="success"
 
+  echo "$testBin $allowComments -b $iter < $file > ${file}.test "
   # parse with a read buffer size ranging from 1-31 to stress stream parsing
-  while (( $iter < 32 )) && [ $success == "success" ] ; do
+  while [ $iter -lt 32  ] && [ $success = "success" ] ; do
     $testBin $allowComments -b $iter < $file > ${file}.test  2>&1
     diff ${DIFF_FLAGS} ${file}.gold ${file}.test
-    if [[ $? == 0 ]] ; then
-      if (( $iter == 31 )) ; then let testsSucceeded+=1 ; fi
+    if [ $? -eq 0 ] ; then
+      if [ $iter -eq 31 ] ; then : $(( testsSucceeded += 1)) ; fi
     else 
       success="FAILURE"
-      let iter=32
+      iter=32
     fi
-    let iter+=1
+    : $(( iter += 1 ))
     rm ${file}.test
   done
 
   echo $success
-  let testsTotal+=1
+  : $(( testsTotal += 1 ))
 done
 
 echo $testsSucceeded/$testsTotal tests successful
 
-if [[ $testsSucceeded != $testsTotal ]] ; then
+if [ $testsSucceeded != $testsTotal ] ; then
   exit 1
 fi
 
