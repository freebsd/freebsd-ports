--- electron/spec/api-screen-spec.ts.orig	2023-01-24 16:58:16 UTC
+++ electron/spec/api-screen-spec.ts
@@ -29,7 +29,7 @@ describe('screen module', () => {
     });
 
     it('has the correct non-object properties', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('scaleFactor').that.is.a('number');
@@ -47,7 +47,7 @@ describe('screen module', () => {
     });
 
     it('has a size object property', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('size').that.is.an('object');
@@ -57,7 +57,7 @@ describe('screen module', () => {
     });
 
     it('has a workAreaSize object property', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('workAreaSize').that.is.an('object');
@@ -67,7 +67,7 @@ describe('screen module', () => {
     });
 
     it('has a bounds object property', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('bounds').that.is.an('object');
