--- newbash.sh.orig	Sun Oct 27 23:53:05 2002
+++ newbash.sh	Sun Oct 27 23:53:54 2002
@@ -1,7 +1,7 @@
 #!/bin/sh
 #
 for FILE in elaps laps make_header post-uninst.sh pre-install.sh prepix \
-	samples.sh samples/makefigs Makefile
+	helpfiles.sh samples/makefigs Makefile
 do
 	mv $FILE $FILE.orig
 	sed 's+/bin/bash+/usr/local/bin/bash+g' $FILE.orig > $FILE
