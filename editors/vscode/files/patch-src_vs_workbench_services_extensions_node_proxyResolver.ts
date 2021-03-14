--- src/vs/workbench/services/extensions/node/proxyResolver.ts.orig	2021-03-04 22:21:59 UTC
+++ src/vs/workbench/services/extensions/node/proxyResolver.ts
@@ -488,7 +488,7 @@ async function readCaCertificates() {
 	if (process.platform === 'darwin') {
 		return readMacCaCertificates();
 	}
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		return readLinuxCaCertificates();
 	}
 	return undefined;
@@ -536,6 +536,8 @@ async function readMacCaCertificates() {
 const linuxCaCertificatePaths = [
 	'/etc/ssl/certs/ca-certificates.crt',
 	'/etc/ssl/certs/ca-bundle.crt',
+	'/etc/ssl/cert.pem',
+	'/usr/local/share/certs/ca-root-nss.crt',
 ];
 
 async function readLinuxCaCertificates() {
