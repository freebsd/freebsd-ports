--- newbash.sh.orig	Tue Sep  3 01:50:01 2002
+++ newbash.sh	Sat Jan 11 15:16:11 2003
@@ -1,10 +1,10 @@
 #!/bin/sh
 #
 for FILE in elaps laps make_header post-uninst.sh pre-install.sh prepix \
-	samples.sh samples/makefigs Makefile
+	helpfiles.sh samples/makefigs Makefile
 do
 	mv $FILE $FILE.orig
-	sed 's+/bin/bash+/usr/local/bin/bash+g' $FILE.orig > $FILE
+	sed 's+/bin/bash+%%LOCALBASE%%/bin/bash+g' $FILE.orig > $FILE
 ##                       ^-----------------^
 ## Replace the portion from + to + of the line above with the path to
 ## bash on your system. Sample replacement line:
