--- node_modules/github/test/github-package.test.js.orig	2019-12-11 02:42:35 UTC
+++ node_modules/github/test/github-package.test.js
@@ -935,7 +935,7 @@ describe('GithubPackage', function() {
 
     describe('when a file change is made outside Atom in workspace 1', function() {
       beforeEach(function() {
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           this.skip();
         }
 
@@ -953,7 +953,7 @@ describe('GithubPackage', function() {
 
     describe('when a file change is made outside Atom in workspace 2', function() {
       beforeEach(function() {
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           this.skip();
         }
 
