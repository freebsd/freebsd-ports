Use _MY_BUILDHASH which is defined in the Port's Makefile

--- scripts/status.sh.orig	2021-02-15 17:35:54 UTC
+++ scripts/status.sh
@@ -1,3 +1,3 @@
 #!/bin/bash
 
-echo "STABLE_BUILDHASH $(git rev-parse --short=8 HEAD || echo nogit)"
+echo "STABLE_BUILDHASH $(git rev-parse --short=8 HEAD || echo %%_MY_BUILDHASH%%)"
