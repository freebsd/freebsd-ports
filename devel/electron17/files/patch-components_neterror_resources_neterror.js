--- components/neterror/resources/neterror.js.orig	2021-11-19 04:25:13 UTC
+++ components/neterror/resources/neterror.js
@@ -129,7 +129,7 @@ function detailsButtonClick() {
 }
 
 let primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
