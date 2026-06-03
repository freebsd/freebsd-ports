--- packages/default-plugins/buildDefaultPlugins.ts.orig	2026-01-10 10:01:41 UTC
+++ packages/default-plugins/buildDefaultPlugins.ts
@@ -1,7 +1,7 @@
 
 /* eslint-disable no-console */
 
-import { copy, exists, remove, readdir, mkdtemp } from 'fs-extra';
+import { copy, exists, remove, mkdtemp } from 'fs-extra';
 import { join, resolve, basename } from 'path';
 import { tmpdir } from 'os';
 import { chdir, cwd } from 'process';
@@ -9,7 +9,6 @@ import getPathToPatchFileFor from './utils/getPathToPa
 import { glob } from 'glob';
 import readRepositoryJson, { BuiltInPluginType, RepositoryData } from './utils/readRepositoryJson';
 import getPathToPatchFileFor from './utils/getPathToPatchFileFor';
-import getCurrentCommitHash from './utils/getCurrentCommitHash';
 import { waitForCliInput } from '@joplin/utils/cli';
 
 interface Options {
@@ -53,32 +52,33 @@ const buildPlugin = async (pluginId: string, repositor
 	const buildDir = await mkdtemp(join(tmpdir(), 'default-plugin-build'));
 	try {
 		logStatus('Building plugin', pluginId, 'at', buildDir);
+		logStatus(`Repository is at ${repositoryData.cloneUrl}`);
 		const pluginDir = resolve(join(pluginSourcesDir, pluginId));
 
 		// Clone the repository if not done yet
-		if (!(await exists(pluginDir)) || (await readdir(pluginDir)).length === 0) {
-			logStatus(`Cloning from repository ${repositoryData.cloneUrl}`);
-			await execCommand(['git', 'clone', '--', repositoryData.cloneUrl, pluginDir]);
-			chdir(pluginDir);
-		}
+		// if (!(await exists(pluginDir)) || (await readdir(pluginDir)).length === 0) {
+		// 	logStatus(`Cloning from repository ${repositoryData.cloneUrl}`);
+		// 	await execCommand(['git', 'clone', '--', repositoryData.cloneUrl, pluginDir]);
+		// 	chdir(pluginDir);
+		// }
 
 		chdir(pluginDir);
-		const expectedCommitHash = repositoryData.commit;
+		// const expectedCommitHash = repositoryData.commit;
 
-		logStatus(`Switching to commit ${expectedCommitHash}`);
-		await execCommand(['git', 'switch', repositoryData.branch]);
+		// logStatus(`Switching to commit ${expectedCommitHash}`);
+		// await execCommand(['git', 'switch', repositoryData.branch]);
 
-		try {
-			await execCommand(['git', 'checkout', expectedCommitHash]);
-		} catch (error) {
-			logStatus(`git checkout failed with error ${error}. Fetching...`);
-			await execCommand(['git', 'fetch']);
-			await execCommand(['git', 'checkout', expectedCommitHash]);
-		}
+		// try {
+		// 	await execCommand(['git', 'checkout', expectedCommitHash]);
+		// } catch (error) {
+		// 	logStatus(`git checkout failed with error ${error}. Fetching...`);
+		// 	await execCommand(['git', 'fetch']);
+		// 	await execCommand(['git', 'checkout', expectedCommitHash]);
+		// }
 
-		if (await getCurrentCommitHash() !== expectedCommitHash) {
-			throw new Error(`Unable to checkout commit ${expectedCommitHash}`);
-		}
+		// if (await getCurrentCommitHash() !== expectedCommitHash) {
+		// 	throw new Error(`Unable to checkout commit ${expectedCommitHash}`);
+		// }
 
 		logStatus('Copying repository files...');
 		await copy(pluginDir, buildDir, {
