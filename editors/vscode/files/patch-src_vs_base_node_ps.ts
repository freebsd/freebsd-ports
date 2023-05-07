--- src/vs/base/node/ps.ts.orig	2023-05-03 19:37:04 UTC
+++ src/vs/base/node/ps.ts
@@ -217,7 +217,7 @@ export function listProcesses(rootPid: number): Promis
 
 			exec('which ps', {}, (err, stdout, stderr) => {
 				if (err || stderr) {
-					if (process.platform !== 'linux') {
+					if (process.platform !== 'linux' && process.platform !== 'freebsd') {
 						reject(err || new Error(stderr.toString()));
 					} else {
 						const cmd = JSON.stringify(FileAccess.asFileUri('vs/base/node/ps.sh').fsPath);
@@ -232,7 +232,8 @@ export function listProcesses(rootPid: number): Promis
 					}
 				} else {
 					const ps = stdout.toString().trim();
-					const args = '-ax -o pid=,ppid=,pcpu=,pmem=,command=';
+					// const args = '-ax -o pid=,ppid=,pcpu=,pmem=,command=';
+					const args = '-ax -o pid= -o ppid= -o pcpu= -o pmem= -o command=';
 
 					// Set numeric locale to ensure '.' is used as the decimal separator
 					exec(`${ps} ${args}`, { maxBuffer: 1000 * 1024, env: { LC_NUMERIC: 'en_US.UTF-8' } }, (err, stdout, stderr) => {
