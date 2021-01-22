--- test/integration/browser/src/index.ts.orig	2020-10-02 16:06:59 UTC
+++ test/integration/browser/src/index.ts
@@ -32,7 +32,7 @@ const height = 800;
 type BrowserType = 'chromium' | 'firefox' | 'webkit';
 
 async function runTestsInBrowser(browserType: BrowserType, endpoint: url.UrlWithStringQuery, server: cp.ChildProcess): Promise<void> {
-	const args = process.platform === 'linux' && browserType === 'chromium' ? ['--no-sandbox'] : undefined; // disable sandbox to run chrome on certain Linux distros
+	const args = (process.platform === 'linux' || process.platform === 'freebsd') && browserType === 'chromium' ? ['--no-sandbox'] : undefined; // disable sandbox to run chrome on certain Linux distros
 	const browser = await playwright[browserType].launch({ headless: !Boolean(optimist.argv.debug), args });
 	const context = await browser.newContext();
 	const page = await context.newPage();
