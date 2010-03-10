--- src/lang/System.cpp.orig	2010-03-10 11:40:35.000000000 +0100
+++ src/lang/System.cpp	2010-03-10 11:41:21.000000000 +0100
@@ -373,13 +373,10 @@
     properties->setProperty(JAKELIB_ONDEMAND(jakelib2_strings[15], new jakelib::lang::String(chars_jakelib2_str_15, 0, 8)), JAKELIB_ONDEMAND(jakelib2_strings[16], new jakelib::lang::String(chars_jakelib2_str_16, 0, 0)) ->plus( cwd));
 
   struct passwd *pw = getpwuid(getuid());
-  if (pw != null)
-    properties->setProperty(JAKELIB_ONDEMAND(jakelib2_strings[17], new jakelib::lang::String(chars_jakelib2_str_17, 0, 9)), JAKELIB_ONDEMAND(jakelib2_strings[18], new jakelib::lang::String(chars_jakelib2_str_18, 0, 0)) ->plus( pw->pw_dir));
-
-  // TODO: cuserid auf dem Mac!
-#if !defined(MACOSX)
-  properties->setProperty(JAKELIB_ONDEMAND(jakelib2_strings[19], new jakelib::lang::String(chars_jakelib2_str_19, 0, 9)), JAKELIB_ONDEMAND(jakelib2_strings[20], new jakelib::lang::String(chars_jakelib2_str_20, 0, 0)) ->plus( cuserid(null)));
-#endif
+  if (pw != null) {
+      properties->setProperty(JAKELIB_ONDEMAND(jakelib2_strings[17], new jakelib::lang::String(chars_jakelib2_str_17, 0, 9)), JAKELIB_ONDEMAND(jakelib2_strings[18], new jakelib::lang::String(chars_jakelib2_str_18, 0, 0)) ->plus( pw->pw_dir));
+      properties->setProperty(JAKELIB_ONDEMAND(jakelib2_strings[19], new jakelib::lang::String(chars_jakelib2_str_19, 0, 9)), JAKELIB_ONDEMAND(jakelib2_strings[20], new jakelib::lang::String(chars_jakelib2_str_20, 0, 0)) ->plus( pw->pw_name));
+  }
 
   struct utsname un;
   if (uname(&un) >= 0) {
