--- test/integration/browser/src/index.ts.orig	2020-05-05 21:48:19 UTC
+++ test/integration/browser/src/index.ts
@@ -30,7 +30,7 @@ const width = 1200;
 const height = 800;
 
 async function runTestsInBrowser(browserType: 'chromium' | 'firefox' | 'webkit', endpoint: url.UrlWithStringQuery, server: cp.ChildProcess): Promise<void> {
-	const args = process.platform === 'linux' && browserType === 'chromium' ? ['--no-sandbox'] : undefined; // disable sandbox to run chrome on certain Linux distros
+	const args = (process.platform === 'linux' || process.platform === 'freebsd') && browserType === 'chromium' ? ['--no-sandbox'] : undefined; // disable sandbox to run chrome on certain Linux distros
 	const browser = await playwright[browserType].launch({ headless: !Boolean(optimist.argv.debug), args });
 	const context = await browser.newContext();
 	const page = await context.newPage();
