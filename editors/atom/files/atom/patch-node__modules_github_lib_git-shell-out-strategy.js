--- node_modules/github/lib/git-shell-out-strategy.js.orig	2019-12-11 03:24:32 UTC
+++ node_modules/github/lib/git-shell-out-strategy.js
@@ -190,7 +190,7 @@ export default class GitShellOutStrategy {
         env.SSH_ASKPASS = normalizeGitHelperPath(gitTempDir.getAskPassSh());
         env.GIT_ASKPASS = normalizeGitHelperPath(gitTempDir.getAskPassSh());
 
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           env.GIT_SSH_COMMAND = gitTempDir.getSshWrapperSh();
         } else if (process.env.GIT_SSH_COMMAND) {
           env.GIT_SSH_COMMAND = process.env.GIT_SSH_COMMAND;
