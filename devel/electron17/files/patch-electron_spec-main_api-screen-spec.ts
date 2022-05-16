--- electron/spec-main/api-screen-spec.ts.orig	2021-04-20 23:32:33 UTC
+++ electron/spec-main/api-screen-spec.ts
@@ -29,7 +29,7 @@ describe('screen module', () => {
     });
 
     it('has the correct non-object properties', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('scaleFactor').that.is.a('number');
@@ -46,7 +46,7 @@ describe('screen module', () => {
     });
 
     it('has a size object property', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('size').that.is.an('object');
@@ -56,7 +56,7 @@ describe('screen module', () => {
     });
 
     it('has a workAreaSize object property', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('workAreaSize').that.is.an('object');
@@ -66,7 +66,7 @@ describe('screen module', () => {
     });
 
     it('has a bounds object property', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('bounds').that.is.an('object');
