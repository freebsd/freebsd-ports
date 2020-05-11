--- node_modules/github/test/git-strategies.test.js.orig	2020-04-22 18:35:27 UTC
+++ node_modules/github/test/git-strategies.test.js
@@ -1536,7 +1536,7 @@ import * as reporterProxy from '../lib/reporter-proxy'
           assert.match(options.env.DISPLAY, /^.+$/);
           assert.match(options.env.SSH_ASKPASS, /git-askpass-atom\.sh$/);
           assert.match(options.env.GIT_ASKPASS, /git-askpass-atom\.sh$/);
-          if (process.platform === 'linux') {
+          if (process.platform === 'linux' || process.platform === 'freebsd') {
             assert.match(options.env.GIT_SSH_COMMAND, /linux-ssh-wrapper\.sh$/);
           }
 
