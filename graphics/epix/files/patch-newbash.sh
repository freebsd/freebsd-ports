--- newbash.sh.orig	Thu Aug 26 21:41:44 2004
+++ newbash.sh	Wed Nov  3 00:52:21 2004
@@ -1,10 +1,10 @@
 #!/bin/sh
 #
 for FILE in elaps laps make_header post-uninst.sh pre-install.sh preflix \
-    prepix samples/sample.sh samples/makefigs Makefile
+    prepix helpfiles.sh samples/sample.sh samples/makefigs Makefile
 do
 	mv $FILE $FILE.orig
-	sed 's+/bin/bash+/usr/local/bin/bash+g' $FILE.orig > $FILE
+	sed 's+/bin/bash+%%LOCALBASE%%/bin/bash+g' $FILE.orig > $FILE
 ##                       ^-----------------^
 ## Replace the portion from + to + of the line above with the path to
 ## bash on your system. Sample replacement line:
