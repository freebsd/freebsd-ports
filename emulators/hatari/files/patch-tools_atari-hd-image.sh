--- tools/atari-hd-image.sh.orig	2024-04-26 10:23:56 UTC
+++ tools/atari-hd-image.sh
@@ -33,8 +33,8 @@ export PATH
 export PATH
 
 # check tools
-if [ -z "$(which mkdosfs)" ] || [ -z "$(which python3)" ]; then
-	echo "ERROR: either mkdosfs or python3 missing!"
+if [ -z "$(which mkdosfs)" ] || [ -z "$(which %%PYTHON_VERSION%%)" ]; then
+	echo "ERROR: either mkdosfs or %%PYTHON_VERSION%% missing!"
 	exit 1
 fi
 
@@ -147,8 +147,8 @@ echo "$step) Create DOS Master Boot Record / partition
 # - http://en.wikipedia.org/wiki/File_Allocation_Table#Boot_Sector
 # For DOS MBR, the values are little endian.
 # -----------
-python3 << EOF
-#!/usr/bin/env python3
+%%PYTHON_VERSION%% << EOF
+#!/usr/bin/env %%PYTHON_VERSION%%
 mbr = bytearray(512)
 
 def set_long(idx, value):
