--- electron/spec/api-screen-spec.ts.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/api-screen-spec.ts
@@ -95,7 +95,7 @@ describe('screen module', () => {
 
       const { size } = display!;
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         expect(size).to.have.property('width').that.is.a('number');
         expect(size).to.have.property('height').that.is.a('number');
       } else {
@@ -109,7 +109,7 @@ describe('screen module', () => {
 
       const { workAreaSize } = display!;
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         expect(workAreaSize).to.have.property('width').that.is.a('number');
         expect(workAreaSize).to.have.property('height').that.is.a('number');
       } else {
@@ -125,7 +125,7 @@ describe('screen module', () => {
       expect(bounds).to.have.property('x').that.is.a('number');
       expect(bounds).to.have.property('y').that.is.a('number');
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         expect(bounds).to.have.property('width').that.is.a('number');
         expect(bounds).to.have.property('height').that.is.a('number');
       } else {
