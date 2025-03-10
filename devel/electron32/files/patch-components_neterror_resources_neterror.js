--- components/neterror/resources/neterror.js.orig	2024-02-21 00:20:41 UTC
+++ components/neterror/resources/neterror.js
@@ -142,7 +142,7 @@ let primaryControlOnLeft = true;
 
 let primaryControlOnLeft = true;
 // clang-format off
-// <if expr="is_macosx or is_ios or is_linux or is_chromeos or is_android">
+// <if expr="is_macosx or is_ios or is_posix or is_chromeos or is_android">
 // clang-format on
 primaryControlOnLeft = false;
 // </if>
