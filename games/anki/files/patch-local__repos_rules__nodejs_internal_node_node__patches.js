Avoid hardcoded paths and Use "shells/bash" from the Ports tree.

--- local_repos/rules_nodejs/internal/node/node_patches.js.orig	2021-02-20 14:13:32 UTC
+++ local_repos/rules_nodejs/internal/node/node_patches.js
@@ -579,7 +579,7 @@ set Path=${nodeDir};%Path%
     else {
         const nodeEntry = path.join(nodeDir, 'node');
         if (!fs$1.existsSync(nodeEntry)) {
-            fs$1.writeFileSync(nodeEntry, `#!/bin/bash
+            fs$1.writeFileSync(nodeEntry, `#!%%LOCALBASE%%/bin/bash
 export NP_SUBPROCESS_NODE_DIR="${nodeDir}"
 export PATH="${nodeDir}":\$PATH
 if [[ ! "\${@}" =~ "${file}" ]]; then
