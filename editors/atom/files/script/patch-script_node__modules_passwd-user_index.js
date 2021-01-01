--- script/node_modules/passwd-user/index.js.orig	2019-12-27 05:40:00 UTC
+++ script/node_modules/passwd-user/index.js
@@ -53,7 +53,7 @@ function extractLinux(line) {
 }
 
 function getUser(str, username) {
-	const extract = process.platform === 'linux' ? extractLinux : extractDarwin;
+	const extract = (process.platform === 'linux' || process.platform === 'freebsd') ? extractLinux : extractDarwin;
 	const lines = str.split('\n');
 	const l = lines.length;
 	let i = 0;
@@ -76,7 +76,7 @@ module.exports = username => {
 		username = process.getuid();
 	}
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		return pify(fs.readFile)('/etc/passwd', 'utf8')
 			.then(passwd => getUser(passwd, username));
 	}
@@ -98,7 +98,7 @@ module.exports.sync = username => {
 		username = process.getuid();
 	}
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		return getUser(fs.readFileSync('/etc/passwd', 'utf8'), username);
 	}
 
