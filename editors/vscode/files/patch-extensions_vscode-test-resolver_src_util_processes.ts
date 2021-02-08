--- extensions/vscode-test-resolver/src/util/processes.ts.orig	2021-02-03 15:33:23 UTC
+++ extensions/vscode-test-resolver/src/util/processes.ts
@@ -20,7 +20,7 @@ export function terminateProcess(p: cp.ChildProcess, e
 		} catch (err) {
 			return { success: false, error: err };
 		}
-	} else if (process.platform === 'darwin' || process.platform === 'linux') {
+	} else if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd') {
 		try {
 			const cmd = path.join(extensionPath, 'scripts', 'terminateProcess.sh');
 			const result = cp.spawnSync(cmd, [p.pid.toString()]);
