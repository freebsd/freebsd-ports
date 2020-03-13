--- electron/spec-main/api-screen-spec.ts.orig	2019-12-13 19:48:14 UTC
+++ electron/spec-main/api-screen-spec.ts
@@ -17,7 +17,7 @@ describe('screen module', () => {
     })
 
     it('has the correct non-object properties', function () {
-      if (process.platform === 'linux') this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip()
       const display = screen.getPrimaryDisplay()
 
       expect(display).to.have.property('scaleFactor').that.is.a('number')
@@ -33,7 +33,7 @@ describe('screen module', () => {
     })
 
     it('has a size object property', function () {
-      if (process.platform === 'linux') this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip()
       const display = screen.getPrimaryDisplay()
 
       expect(display).to.have.property('size').that.is.an('object')
@@ -43,7 +43,7 @@ describe('screen module', () => {
     })
 
     it('has a workAreaSize object property', function () {
-      if (process.platform === 'linux') this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip()
       const display = screen.getPrimaryDisplay()
 
       expect(display).to.have.property('workAreaSize').that.is.an('object')
@@ -53,7 +53,7 @@ describe('screen module', () => {
     })
 
     it('has a bounds object property', function () {
-      if (process.platform === 'linux') this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip()
       const display = screen.getPrimaryDisplay()
 
       expect(display).to.have.property('bounds').that.is.an('object')
