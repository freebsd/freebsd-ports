--- tools/atari-hd-image.sh.orig	2022-02-26 12:11:11 UTC
+++ tools/atari-hd-image.sh
@@ -33,8 +33,8 @@ PATH=/sbin:$PATH
 export PATH
 
 # check tools
-if [ -z "$(which mkdosfs)" ] || [ -z "$(which python)" ]; then
-	echo "ERROR: either mkdosfs or python tool missing!"
+if [ -z "$(which mkdosfs)" ] || [ -z "$(which %%PYTHON_VERSION%%)" ]; then
+	echo "ERROR: either mkdosfs or %%PYTHON_VERSION%% tool missing!"
 	exit 1
 fi
 
@@ -147,8 +147,8 @@ echo "$step) Create DOS Master Boot Record / partition
 # - http://en.wikipedia.org/wiki/File_Allocation_Table#Boot_Sector
 # For DOS MBR, the values are little endian.
 # -----------
-python << EOF
-#!/usr/bin/env python3
+%%PYTHON_VERSION%% << EOF
+#!/usr/bin/env %%PYTHON_VERSION%%3
 mbr = bytearray(512)
 
 def set_long(idx, value):
