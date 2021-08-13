Avoid hardcoded paths and Use "shells/bash" from the Ports tree.

--- local_repos/rules_nodejs/internal/node/node_patches.js.orig	2021-08-02 17:17:08 UTC
+++ local_repos/rules_nodejs/internal/node/node_patches.js
@@ -560,7 +560,7 @@ set Path=${nodeDir};%Path%
     else {
         const nodeEntry = path__default['default'].join(nodeDir, 'node');
         if (!fs__default['default'].existsSync(nodeEntry)) {
-            fs__default['default'].writeFileSync(nodeEntry, `#!/bin/bash
+            fs__default['default'].writeFileSync(nodeEntry, `#!%%LOCALBASE%%/bin/bash
 export NP_SUBPROCESS_NODE_DIR="${nodeDir}"
 export PATH="${nodeDir}":\$PATH
 if [[ ! "\${@}" =~ "${file}" ]]; then
