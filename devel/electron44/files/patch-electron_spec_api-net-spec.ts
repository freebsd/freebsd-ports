--- electron/spec/api-net-spec.ts.orig	2026-09-18 15:43:03 UTC
+++ electron/spec/api-net-spec.ts
@@ -2104,7 +2104,7 @@ describe('net module', () => {
   // The select-client-certificate event only fires when the platform cert
   // store yields at least one matching identity, which the test suite cannot
   // guarantee on Linux (NSS) without app.importCertificate.
-  ifdescribe(process.platform !== 'linux')('client certificate authentication', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('client certificate authentication', () => {
     let server: https.Server;
     let secureUrl: string;
     const certPath = path.join(fixturesPath, 'certificates');
