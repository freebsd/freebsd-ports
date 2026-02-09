--- src/vs/base/node/ps.ts.orig	2026-02-04 01:55:52 UTC
+++ src/vs/base/node/ps.ts
@@ -217,7 +217,7 @@ export function listProcesses(rootPid: number): Promis
 					}
 				} else {
 					const ps = stdout.toString().trim();
-					const args = '-ax -o pid=,ppid=,pcpu=,pmem=,command=';
+					const args = '-ax -o pid= -o ppid= -o pcpu= -o pmem= -o command=';
 
 					// Set numeric locale to ensure '.' is used as the decimal separator
 					exec(`${ps} ${args}`, { maxBuffer: 1000 * 1024, env: { LC_NUMERIC: 'en_US.UTF-8' } }, (err, stdout, stderr) => {
