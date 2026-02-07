Fix build with clang 6

migration.cpp:134:27: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
    "The location of the "APP_NAME" configuration directory has changed.\n"
                          ^
                           
migration.cpp:144:33: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
    " Click  [Cancel]  to exit "APP_NAME" now without any changes.\n"

--- src/migration.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/migration.cpp
@@ -131,7 +131,7 @@ void MigrateConfigDir(FXApp*a, const FXString &src, co
     _("IMPORTANT NOTICE"),
     _(
     "\n"
-    "The location of the "APP_NAME" configuration directory has changed.\n"
+    "The location of the " APP_NAME " configuration directory has changed.\n"
     "\n"
 #ifndef WIN32
     "This is due to changes in the FOX toolkit, in accordance with\n"
@@ -141,7 +141,7 @@ void MigrateConfigDir(FXApp*a, const FXString &src, co
     "Migration options:\n"
     " Click  [ Yes ]  to automatically copy your old settings (recommended).\n"
     " Click  [ No ]  to create a new configuration.\n"
-    " Click  [Cancel]  to exit "APP_NAME" now without any changes.\n"
+    " Click  [Cancel]  to exit " APP_NAME " now without any changes.\n"
     "\n"
     "Do you want me to copy your existing configuration?"
     ),
