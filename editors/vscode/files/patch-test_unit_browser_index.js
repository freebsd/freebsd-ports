--- test/unit/browser/index.js.orig	2021-03-11 08:29:15 UTC
+++ test/unit/browser/index.js
@@ -146,7 +146,7 @@ function consoleLogFn(msg) {
 }
 
 async function runTestsInBrowser(testModules, browserType) {
-	const args = process.platform === 'linux' && browserType === 'chromium' ? ['--no-sandbox'] : undefined; // disable sandbox to run chrome on certain Linux distros
+	const args = (process.platform === 'linux' || process.platform === 'freebsd') && browserType === 'chromium' ? ['--no-sandbox'] : undefined; // disable sandbox to run chrome on certain Linux distros
 	const browser = await playwright[browserType].launch({ headless: !Boolean(argv.debug), args });
 	const context = await browser.newContext();
 	const page = await context.newPage();
