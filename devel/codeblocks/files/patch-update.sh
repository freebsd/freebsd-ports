--- update.sh.orig	Sun Nov 27 15:13:34 2005
+++ update.sh	Sun Nov 27 15:14:03 2005
@@ -57,10 +57,6 @@
 cp -f devel/*.exe output > /dev/null
 cp -f devel/*.so output > /dev/null
 cp -f ${RESDIR}/plugins/*.so output/share/CodeBlocks/plugins > /dev/null
-echo Stripping debug info from output tree
-strip output/*.exe
-strip output/*.so
-strip output/share/CodeBlocks/plugins/*.so
 
 echo Creating launch-scripts
 echo -e "#!/bin/sh\n" > output/run.sh
