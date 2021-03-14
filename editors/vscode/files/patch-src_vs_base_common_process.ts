--- src/vs/base/common/process.ts.orig	2021-03-11 08:30:51 UTC
+++ src/vs/base/common/process.ts
@@ -19,7 +19,7 @@ else if (typeof globals.vscode !== 'undefined') {
 	safeProcess = {
 
 		// Supported
-		get platform(): 'win32' | 'linux' | 'darwin' { return globals.vscode.process.platform; },
+		get platform(): 'win32' | 'linux' | 'freebsd' | 'darwin' { return globals.vscode.process.platform; },
 		get env() { return globals.vscode.process.env; },
 		nextTick(callback: (...args: any[]) => void): void { return setImmediate(callback); },
 
