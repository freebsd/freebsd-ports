--- sqldeveloper.sh.orig
+++ sqldeveloper.sh
@@ -1,2 +1,2 @@
 #!/bin/bash
-cd "`dirname $0`"/sqldeveloper/bin && bash sqldeveloper $*
+cd %DATADIR%/sqldeveloper/bin && JAVA_HOME=%JAVA_HOME% exec bash sqldeveloper $*
