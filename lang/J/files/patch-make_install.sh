--- make/install.sh.orig	2018-02-24 19:49:42 UTC
+++ make/install.sh
@@ -1,14 +1,7 @@
 #!/usr/local/bin/bash
 # install jbld folders - new install or a reinstall
 
-cd ~
-if [ ! -f jvars.sh ]; then
- echo "~/jvars.sh must exist"
- exit 1
-fi
-
-cd ~
-. jvars.sh
+. make/jvars.sh
 
 rm -f -r $jbld
 mkdir $jbld
