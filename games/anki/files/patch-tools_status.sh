Use _MY_BUILDHASH which is defined in the Port's Makefile

--- tools/status.sh.orig	2022-06-05 15:45:44 UTC
+++ tools/status.sh
@@ -1,3 +1,3 @@
 #!/bin/bash
 
-echo "STABLE_BUILDHASH $(git rev-parse --short=8 HEAD || echo nogit)"
+echo "STABLE_BUILDHASH $(git rev-parse --short=8 HEAD || echo %%_MY_BUILDHASH%%)"
