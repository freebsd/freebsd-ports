--- node_modules/boxednode/lib/index.js.orig	2026-10-27 16:03:57 UTC
+++ node_modules/boxednode/lib/index.js
@@ -50,8 +50,8 @@ async function getNodeSourceForVersion(range, dir, log
     try {
         inputIsFileUrl = new url_1.URL(range).protocol === 'file:';
     }
-    catch (_a) { }
-    if (inputIsFileUrl) {
+    catch (_a) { console.error(_a) }
+    if (false) {
         logger.stepStarting(`Extracting tarball from ${range} to ${dir}`);
         await fs_1.promises.mkdir(dir, { recursive: true });
         await (0, helpers_1.pipeline)((0, fs_1.createReadStream)((0, url_1.fileURLToPath)(range)), zlib_1.default.createGunzip(), tar.x({
@@ -72,7 +72,7 @@ async function getNodeSourceForVersion(range, dir, log
         releaseBaseUrl = `https://nodejs.org/download/nightly/${version}`;
     }
     else {
-        const ver = (await (0, nv_1.default)(range)).pop();
+        const ver = {"version":"%%NODEJS_PORTVERSION%%"};
         if (!ver) {
             throw new Error(`No node version found for ${range}`);
         }
@@ -80,29 +80,29 @@ async function getNodeSourceForVersion(range, dir, log
         releaseBaseUrl = `https://nodejs.org/download/release/${version}`;
     }
     const tarballName = `node-${version}.tar.gz`;
-    const cachedTarballPath = path_1.default.join(dir, tarballName);
+    const cachedTarballPath = url_1.fileURLToPath(range);
     let hasCachedTarball = false;
     try {
         hasCachedTarball = (await fs_1.promises.stat(cachedTarballPath)).size > 0;
     }
-    catch (_b) { }
+    catch (_b) { console.error(_b) }
     if (hasCachedTarball) {
-        const shaSumsUrl = `${releaseBaseUrl}/SHASUMS256.txt`;
+        const shaSumsUrl = `%%NODEJS_SHAFILE%%`;
         logger.stepStarting(`Verifying existing tarball via ${shaSumsUrl}`);
         const [expectedSha, realSha] = await Promise.all([
             (async () => {
                 try {
-                    const shaSums = await (0, node_fetch_1.default)(shaSumsUrl);
+                    const shaSums = {"ok":1};
                     if (!shaSums.ok)
                         return;
-                    const text = await shaSums.text();
+                    const text = await fs_1.promises.readFile(shaSumsUrl, 'utf8');
                     for (const line of text.split('\n')) {
                         if (line.trim().endsWith(tarballName)) {
                             return line.match(/^([0-9a-fA-F]+)\b/)[0];
                         }
                     }
                 }
-                catch (_a) { }
+                catch (_a) { console.error(_a) }
             })(),
             (async () => {
                 const hash = crypto_1.default.createHash('sha256');
@@ -193,6 +193,10 @@ async function compileNode(sourcePath, linkedJSModules
         for (const module of linkedJSModules) {
             configure.push('--link-module', module);
         }
+        for (const static_lib of ['ada', 'brotli', 'cares', 'corepack', 'googletest', 'histogram', 'icu-small', 'llhttp',
+            'merve', 'nbytes', 'nghttp2', 'ngtcp2', 'npm', 'simdjson', 'sqlite', 'uv', 'uvwasi', 'zlib', 'zstd']) {
+            await fs_1.promises.rm(path_1.default.join(sourcePath, 'deps', static_lib), { recursive: true, force: true });
+        }
         await (0, helpers_1.spawnBuildCommand)(configure, options);
         if (configure.includes('--fully-static') || configure.includes('--partly-static')) {
             for (const file of [
@@ -211,7 +215,7 @@ async function compileNode(sourcePath, linkedJSModules
                 await fs_1.promises.writeFile(target, source);
             }
         }
-        const make = ['make', ...makeArgs];
+        const make = ['%%GMAKE%%', ...makeArgs];
         if (!make.some((arg) => /^-j/.test(arg))) {
             make.push(`-j${cpus}`);
         }
@@ -259,7 +263,7 @@ async function compileJSFileAsBinaryImpl(options, logg
     await fs_1.promises.access(options.sourceFile);
     const namespace = options.namespace || path_1.default.basename(options.sourceFile, '.js');
     if (!options.tmpdir) {
-        options.tmpdir = path_1.default.join(os_1.default.tmpdir(), 'boxednode', namespace);
+        options.tmpdir = path_1.default.join('%%WRKDIR%%', 'boxednode', namespace);
     }
     const nodeSourcePath = await getNodeSourceForVersion(options.nodeVersionRange, options.tmpdir, logger);
     const nodeVersion = await getNodeVersionFromSourceDirectory(nodeSourcePath);
