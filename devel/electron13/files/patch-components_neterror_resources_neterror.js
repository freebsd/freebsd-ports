--- components/neterror/resources/neterror.js.orig	2021-04-14 01:08:45 UTC
+++ components/neterror/resources/neterror.js
@@ -144,7 +144,7 @@ function detailsButtonClick() {
 }
 
 let primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
