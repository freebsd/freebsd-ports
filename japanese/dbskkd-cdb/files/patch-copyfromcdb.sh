--- copyfromcdb.sh.dist	Sat Mar 25 23:26:43 2000
+++ copyfromcdb.sh	Sat Oct 30 00:51:56 2004
@@ -1,7 +1,7 @@
 #!/bin/sh
 # $Id: copyfromcdb.sh,v 1.1 2000/03/25 14:26:10 kenji Exp $
 
-CDBDIR=~/src/cdb-0.75
+CDBDIR=%%CDBDIR%%
 CP=/bin/cp
 
 ${CP} ${CDBDIR}/byte.h .
