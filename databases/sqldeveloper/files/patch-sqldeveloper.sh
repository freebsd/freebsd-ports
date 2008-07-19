--- sqldeveloper.sh.orig	2008-07-16 21:07:00.000000000 +0200
+++ sqldeveloper.sh	2008-07-16 21:10:20.000000000 +0200
@@ -1,2 +1,2 @@
 #!/bin/bash
-cd "`dirname $0`"/sqldeveloper/bin && bash sqldeveloper $*
+cd %DATADIR%/sqldeveloper/bin && JAVA_HOME=%JAVA_HOME% exec bash sqldeveloper $*
