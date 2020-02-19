--- src/update-process-env.js.orig	2019-10-21 17:33:40 UTC
+++ src/update-process-env.js
@@ -8,7 +8,7 @@ const ENVIRONMENT_VARIABLES_TO_PRESERVE = new Set([
   'ATOM_DISABLE_SHELLING_OUT_FOR_ENVIRONMENT'
 ]);
 
-const PLATFORMS_KNOWN_TO_WORK = new Set(['darwin', 'linux']);
+const PLATFORMS_KNOWN_TO_WORK = new Set(['darwin', 'linux', 'freebsd']);
 
 async function updateProcessEnv(launchEnv) {
   let envToAssign;
