--- test/integration/browser/src/index.ts.orig	2020-03-10 09:27:36 UTC
+++ test/integration/browser/src/index.ts
@@ -30,7 +30,7 @@ const width = 1200;
 const height = 800;
 
 async function runTestsInBrowser(browserType: 'chromium' | 'firefox' | 'webkit', endpoint: url.UrlWithStringQuery, server: cp.ChildProcess): Promise<void> {
-	const args = process.platform === 'linux' && browserType === 'chromium' ? ['--no-sandbox'] : undefined; // disable sandbox to run chrome on certain Linux distros
+	const args = (process.platform === 'linux' || process.platform === 'freebsd') && browserType === 'chromium' ? ['--no-sandbox'] : undefined; // disable sandbox to run chrome on certain Linux distros
 	const browser = await playwright[browserType].launch({ headless: !Boolean(optimist.argv.debug), dumpio: true, args });
 	const context = await browser.newContext();
 	const page = await context.newPage();
