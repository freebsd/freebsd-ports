--- node_modules/github/test/git-strategies.test.js.orig	2019-12-11 03:24:32 UTC
+++ node_modules/github/test/git-strategies.test.js
@@ -1535,7 +1535,7 @@ import * as reporterProxy from '../lib/reporter-proxy'
           assert.match(options.env.DISPLAY, /^.+$/);
           assert.match(options.env.SSH_ASKPASS, /git-askpass-atom\.sh$/);
           assert.match(options.env.GIT_ASKPASS, /git-askpass-atom\.sh$/);
-          if (process.platform === 'linux') {
+          if (process.platform === 'linux' || process.platform === 'freebsd') {
             assert.match(options.env.GIT_SSH_COMMAND, /linux-ssh-wrapper\.sh$/);
           }
 
