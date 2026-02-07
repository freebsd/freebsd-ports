--- tools/atari-hd-image.sh.orig	2025-08-09 22:33:00 UTC
+++ tools/atari-hd-image.sh
@@ -33,8 +33,8 @@ export PATH
 export PATH
 
 # check tools
-if [ -z "$(which mkdosfs)" ] || [ -z "$(which python3)" ]; then
-	echo "ERROR: either mkdosfs or python3 missing!"
+if [ -z "$(which mkdosfs)" ] || [ -z "$(which %%PYTHON_CMD%%)" ]; then
+	echo "ERROR: either mkdosfs or %%PYTHON_CMD%% missing!"
 	exit 1
 fi
 
@@ -147,7 +147,7 @@ echo "$step) Create DOS Master Boot Record / partition
 # - http://en.wikipedia.org/wiki/File_Allocation_Table#Boot_Sector
 # For DOS MBR, the values are little endian.
 # -----------
-python3 << EOF
+%%PYTHON_CMD%% << EOF
 #!/usr/bin/python3
 mbr = bytearray(512)
 
