$FreeBSD$

--- bin/poseidon.sh.orig	Fri Sep 24 11:55:20 2004
+++ bin/poseidon.sh	Mon Nov 22 00:58:46 2004
@@ -1,4 +1,9 @@
-#!/bin/bash
+#!/bin/sh
+
+JAVA_HOME="/usr/local/jdk1.4.2"
+POSEIDONCE_HOME="$HOME/.poseidon"
+POSEIDONSE_HOME="$HOME/.poseidon"
+POSEIDONPE_HOME="$HOME/.poseidon"
 
 resolvePath() {
 	cmd=`basename "${1}"`
@@ -29,7 +34,7 @@
 cmd=`resolvePath "$0"`
 echo "Absolute path: $cmd"
 instdir=`dirname "$cmd"`
-if [[ ! (-z "$1")]] ; then
+if [ -n "$1" ] ; then
     project=`resolvePath "$1"`
     echo "Project to load: $project"
     loglevel=$2
