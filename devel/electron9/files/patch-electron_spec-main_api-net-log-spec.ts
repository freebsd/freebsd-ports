--- electron/spec-main/api-net-log-spec.ts.orig	2020-05-18 21:17:08 UTC
+++ electron/spec-main/api-net-log-spec.ts
@@ -124,7 +124,7 @@ describe('netLog module', () => {
     expect(JSON.parse(dump).events.some((x: any) => x.params && x.params.bytes && Buffer.from(x.params.bytes, 'base64').includes(unique))).to.be.true('uuid present in dump');
   });
 
-  ifit(process.platform !== 'linux')('should begin and end logging automatically when --log-net-log is passed', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should begin and end logging automatically when --log-net-log is passed', async () => {
     const appProcess = ChildProcess.spawn(process.execPath,
       [appPath], {
         env: {
@@ -137,7 +137,7 @@ describe('netLog module', () => {
     expect(fs.existsSync(dumpFile)).to.be.true('dump file exists');
   });
 
-  ifit(process.platform !== 'linux')('should begin and end logging automtically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should begin and end logging automtically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called', async () => {
     const appProcess = ChildProcess.spawn(process.execPath,
       [appPath], {
         env: {
@@ -153,7 +153,7 @@ describe('netLog module', () => {
     expect(fs.existsSync(dumpFileDynamic)).to.be.true('dynamic dump file exists');
   });
 
-  ifit(process.platform !== 'linux')('should end logging automatically when only .startLogging() is called', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should end logging automatically when only .startLogging() is called', async () => {
     const appProcess = ChildProcess.spawn(process.execPath,
       [appPath], {
         env: {
