--- electron/spec/api-screen-spec.js.orig	2019-09-11 17:30:11 UTC
+++ electron/spec/api-screen-spec.js
@@ -17,7 +17,7 @@ describe('screen module', () => {
     })
 
     it('has the correct non-object properties', function () {
-      if (process.platform === 'linux') this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip()
       const display = screen.getPrimaryDisplay()
 
       expect(display).to.have.a.property('scaleFactor').that.is.a('number')
@@ -33,7 +33,7 @@ describe('screen module', () => {
     })
 
     it('has a size object property', function () {
-      if (process.platform === 'linux') this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip()
       const display = screen.getPrimaryDisplay()
 
       expect(display).to.have.a.property('size').that.is.an('object')
@@ -43,7 +43,7 @@ describe('screen module', () => {
     })
 
     it('has a workAreaSize object property', function () {
-      if (process.platform === 'linux') this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip()
       const display = screen.getPrimaryDisplay()
 
       expect(display).to.have.a.property('workAreaSize').that.is.an('object')
@@ -53,7 +53,7 @@ describe('screen module', () => {
     })
 
     it('has a bounds object property', function () {
-      if (process.platform === 'linux') this.skip()
+      if (process.platform === 'linux' || process.platform === 'freebsd') this.skip()
       const display = screen.getPrimaryDisplay()
 
       expect(display).to.have.a.property('bounds').that.is.an('object')
