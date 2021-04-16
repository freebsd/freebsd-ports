--- yaze.sh.orig	2015-04-26 14:15:29 UTC
+++ yaze.sh
@@ -1,9 +1,10 @@
 #!/bin/sh
 
-S_YAZEFILES=/usr/local/lib/yaze
-S_CPMDSKS=/usr/local/lib/yaze/disks
-S_DOCFILES=/usr/local/lib/yaze/doc
-S_DOCFILES_html=/usr/local/lib/yaze/doc_html
+S_YAZEEXECDIR=%%LIBEXECDIR%%
+S_YAZEFILES=%%DATADIR%%
+S_CPMDSKS=%%DATADIR%%/disks
+S_DOCFILES=%%DOCSDIR%%
+S_DOCFILES_html=%%DOCSDIR%%/html
 
 if [ ! -f .yazerc ]
 then
@@ -80,10 +81,10 @@ fi
 echo
 echo pwd=`pwd`
 
-if [ -f yaze_bin ]
+if [ -f $S_YAZEEXECDIR/yaze_bin ]
 then
-   echo "starting ./yaze_bin $*"
-   exec ./yaze_bin $*
+   echo "starting $S_YAZEEXECDIR/yaze_bin $*"
+   exec $S_YAZEEXECDIR/yaze_bin $*
 else
    echo "starting yaze_bin $*"
    exec yaze_bin $*
