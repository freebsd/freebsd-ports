--- src/lang/System.cpp.orig	Sun Feb 19 15:01:10 2006
+++ src/lang/System.cpp	Thu Jul  5 01:53:34 2007
@@ -373,10 +373,11 @@
     properties->setProperty(JAKELIB_ONDEMAND(jakelib2_strings[15], new jakelib::lang::String(chars_jakelib2_str_15, 0, 8)), JAKELIB_ONDEMAND(jakelib2_strings[16], new jakelib::lang::String(chars_jakelib2_str_16, 0, 0)) ->plus( cwd));
 
   struct passwd *pw = getpwuid(getuid());
-  if (pw != null)
+  if (pw != null) {
     properties->setProperty(JAKELIB_ONDEMAND(jakelib2_strings[17], new jakelib::lang::String(chars_jakelib2_str_17, 0, 9)), JAKELIB_ONDEMAND(jakelib2_strings[18], new jakelib::lang::String(chars_jakelib2_str_18, 0, 0)) ->plus( pw->pw_dir));
 
-  properties->setProperty(JAKELIB_ONDEMAND(jakelib2_strings[19], new jakelib::lang::String(chars_jakelib2_str_19, 0, 9)), JAKELIB_ONDEMAND(jakelib2_strings[20], new jakelib::lang::String(chars_jakelib2_str_20, 0, 0)) ->plus( cuserid(null)));
+    properties->setProperty(JAKELIB_ONDEMAND(jakelib2_strings[19], new jakelib::lang::String(chars_jakelib2_str_19, 0, 9)), JAKELIB_ONDEMAND(jakelib2_strings[20], new jakelib::lang::String(chars_jakelib2_str_20, 0, 0)) ->plus( pw->pw_name));
+  }
 
   struct utsname un;
   if (uname(&un) >= 0) {
