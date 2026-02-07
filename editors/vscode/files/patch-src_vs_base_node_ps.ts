--- src/vs/base/node/ps.ts.orig	2025-12-10 18:02:22 UTC
+++ src/vs/base/node/ps.ts
@@ -223,7 +223,7 @@ export function listProcesses(rootPid: number): Promis
 					}
 				} else {
 					const ps = stdout.toString().trim();
-					const args = '-ax -o pid=,ppid=,pcpu=,pmem=,command=';
+					const args = '-ax -o pid= -o ppid= -o pcpu= -o pmem= -o command=';
 
 					// Set numeric locale to ensure '.' is used as the decimal separator
 					exec(`${ps} ${args}`, { maxBuffer: 1000 * 1024, env: { LC_NUMERIC: 'en_US.UTF-8' } }, (err, stdout, stderr) => {
