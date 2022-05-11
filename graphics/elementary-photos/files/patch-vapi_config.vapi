--- vapi/config.vapi.orig	2022-02-01 18:38:16 UTC
+++ vapi/config.vapi
@@ -5,16 +5,16 @@
  */
 
 [CCode (cheader_filename="config.h")]
-extern const string _PREFIX;
+public const string _PREFIX;
 [CCode (cheader_filename="config.h")]
-extern const string _VERSION;
+public const string _VERSION;
 [CCode (cheader_filename="config.h")]
-extern const string GETTEXT_PACKAGE;
+public const string GETTEXT_PACKAGE;
 [CCode (cheader_filename="config.h")]
-extern const string LOCALEDIR;
+public const string LOCALEDIR;
 [CCode (cheader_filename="config.h")]
-extern const string _LIB;
+public const string _LIB;
 [CCode (cheader_filename="config.h")]
-extern const string _LIBEXECDIR;
+public const string _LIBEXECDIR;
 [CCode (cheader_filename="config.h")]
-extern const string PROJECT_NAME;
+public const string PROJECT_NAME;
