--- sqldeveloper.sh.orig	2008-04-21 08:33:48.000000000 +0200
+++ sqldeveloper.sh	2008-05-15 12:02:13.000000000 +0200
@@ -1,2 +1,2 @@
 #!/bin/bash
-cd "`dirname $0`"/sqldeveloper/bin && bash sqldeveloper $*
+cd %DATADIR%/sqldeveloper/bin && JAVA_HOME=%JAVA_HOME% bash sqldeveloper $*
