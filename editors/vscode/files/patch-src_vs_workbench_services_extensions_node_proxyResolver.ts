--- src/vs/workbench/services/extensions/node/proxyResolver.ts.orig	2020-04-16 15:59:11 UTC
+++ src/vs/workbench/services/extensions/node/proxyResolver.ts
@@ -486,7 +486,7 @@ async function readCaCertificates() {
 	if (process.platform === 'darwin') {
 		return readMacCaCertificates();
 	}
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		return readLinuxCaCertificates();
 	}
 	return undefined;
@@ -535,6 +535,8 @@ async function readMacCaCertificates() {
 const linuxCaCertificatePaths = [
 	'/etc/ssl/certs/ca-certificates.crt',
 	'/etc/ssl/certs/ca-bundle.crt',
+	'/etc/ssl/cert.pem',
+	'/usr/local/share/certs/ca-root-nss.crt',
 ];
 
 async function readLinuxCaCertificates() {
