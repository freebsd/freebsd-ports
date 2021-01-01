--- node_modules/github/lib/models/workdir-context.js.orig	2019-08-21 13:55:10 UTC
+++ node_modules/github/lib/models/workdir-context.js
@@ -116,7 +116,7 @@ export default class WorkdirContext {
   }
 
   useWorkspaceChangeObserver() {
-    return !!process.env.ATOM_GITHUB_WORKSPACE_OBSERVER || process.platform === 'linux';
+    return !!process.env.ATOM_GITHUB_WORKSPACE_OBSERVER || (process.platform === 'linux' || process.platform === 'freebsd');
   }
 
   // Event subscriptions
