--- sqldeveloper.sh.orig	Tue Jan 15 22:18:13 2008
+++ sqldeveloper.sh	Tue Jan 15 22:18:30 2008
@@ -1,2 +1,2 @@
 #!/bin/bash
-cd "`dirname $0`"/sqldeveloper/bin && bash sqldeveloper $*
+cd %DATADIR%/sqldeveloper/bin && sh sqldeveloper $*
