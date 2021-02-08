--- electron/spec-main/api-screen-spec.ts.orig	2021-01-22 23:55:24 UTC
+++ electron/spec-main/api-screen-spec.ts
@@ -29,7 +29,7 @@ describe('screen module', () => {
     });
 
     it('has the correct non-object properties', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('scaleFactor').that.is.a('number');
@@ -45,7 +45,7 @@ describe('screen module', () => {
     });
 
     it('has a size object property', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('size').that.is.an('object');
@@ -55,7 +55,7 @@ describe('screen module', () => {
     });
 
     it('has a workAreaSize object property', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('workAreaSize').that.is.an('object');
@@ -65,7 +65,7 @@ describe('screen module', () => {
     });
 
     it('has a bounds object property', function () {
-      if (process.platform === 'linux') this.skip();
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip();
       const display = screen.getPrimaryDisplay();
 
       expect(display).to.have.property('bounds').that.is.an('object');
