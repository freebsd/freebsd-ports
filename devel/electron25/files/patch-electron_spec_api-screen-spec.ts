--- electron/spec/api-screen-spec.ts.orig	2023-05-31 14:28:29 UTC
+++ electron/spec/api-screen-spec.ts
@@ -29,7 +29,7 @@ describe('screen module', () => {
       expect(display).to.be.an('object');
     });
 
-    ifit(process.platform !== 'linux')('has the correct non-object properties', function () {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('has the correct non-object properties', function () {
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('scaleFactor').that.is.a('number');
@@ -46,7 +46,7 @@ describe('screen module', () => {
       expect(display).to.have.property('displayFrequency').that.is.a('number');
     });
 
-    ifit(process.platform !== 'linux')('has a size object property', function () {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('has a size object property', function () {
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('size').that.is.an('object');
@@ -55,7 +55,7 @@ describe('screen module', () => {
       expect(size).to.have.property('height').that.is.greaterThan(0);
     });
 
-    ifit(process.platform !== 'linux')('has a workAreaSize object property', function () {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('has a workAreaSize object property', function () {
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('workAreaSize').that.is.an('object');
@@ -64,7 +64,7 @@ describe('screen module', () => {
       expect(workAreaSize).to.have.property('height').that.is.greaterThan(0);
     });
 
-    ifit(process.platform !== 'linux')('has a bounds object property', function () {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('has a bounds object property', function () {
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('bounds').that.is.an('object');
