--- tvdownloader.sh.orig	2010-10-16 16:27:16.000000000 +0200
+++ tvdownloader.sh	2010-12-19 23:38:13.000000000 +0100
@@ -1,20 +1,5 @@
-#!/bin/bash
+#! /bin/sh
+# $FreeBSD$
 
 cd "__DATADIR__/tvdownloader/"
-
-if [ ! -z "`python --version 2>&1 | grep 'Python 2'`" ]
-then
-	python main.py "$*"
-else
-	if [ -x "/usr/bin/python2.7" ]
-	then
-		python2.7 main.py "$*"
-	else
-		if [ -x "/usr/bin/python2.6" ]
-		then
-			python2.6 main.py "$*"
-		else
-			echo "Erreur : impossible de trouver une version de Python 2"
-		fi
-	fi
-fi
\ No newline at end of file
+exec %%PYTHON_CMD%% main.py
