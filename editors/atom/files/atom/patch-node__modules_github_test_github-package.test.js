--- node_modules/github/test/github-package.test.js.orig	2020-02-05 20:24:36 UTC
+++ node_modules/github/test/github-package.test.js
@@ -1040,7 +1040,7 @@ describe('GithubPackage', function() {
 
     describe('when a file change is made outside Atom in workspace 1', function() {
       beforeEach(function() {
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           this.skip();
         }
 
@@ -1058,7 +1058,7 @@ describe('GithubPackage', function() {
 
     describe('when a file change is made outside Atom in workspace 2', function() {
       beforeEach(function() {
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           this.skip();
         }
 
