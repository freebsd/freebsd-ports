--- pylib/cassandra-cqlsh-tests.sh.orig	2020-10-20 17:07:48 UTC
+++ pylib/cassandra-cqlsh-tests.sh
@@ -1,4 +1,4 @@
-#!/bin/bash -x
+#!/usr/local/bin/bash -x
 
 ################################
 #
@@ -9,6 +9,8 @@
 WORKSPACE=$1
 PYTHON_VERSION=$2
 JAVA_HOME=$3
+REPO_DIR=$4
+PYTHON_CMD=$5
 
 if [ "${WORKSPACE}" = "" ]; then
     echo "Specify Cassandra source directory"
@@ -48,7 +50,7 @@ fi
 
 # Loop to prevent failure due to maven-ant-tasks not downloading a jar..
 for x in $(seq 1 3); do
-    ant -buildfile ${CASSANDRA_DIR}/build.xml realclean jar
+    ant -buildfile ${CASSANDRA_DIR}/build.xml -Dmaven.repo.local=${REPO_DIR} -Dlocalm2=${REPO_DIR} -Dpycmd=${PYTHON_CMD} realclean jar
     RETURN="$?"
     if [ "${RETURN}" -eq "0" ]; then
         break
@@ -62,7 +64,7 @@ fi
 
 # Set up venv with dtest dependencies
 set -e # enable immediate exit if venv setup fails
-virtualenv --python=$PYTHON_VERSION venv
+virtualenv --python=${PYTHON_CMD} venv
 source venv/bin/activate
 pip install -r ${CASSANDRA_DIR}/pylib/requirements.txt
 pip freeze
@@ -103,7 +105,7 @@ case "${pre_or_post_cdc}" in
         ;;
 esac
 
-ccm start --wait-for-binary-proto
+ccm start --wait-for-binary-proto --root
 
 cd ${CASSANDRA_DIR}/pylib/cqlshlib/
 
