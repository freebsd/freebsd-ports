--- Source_Files/Misc/preferences.cpp.orig	2008-07-22 04:06:39.000000000 +0400
+++ Source_Files/Misc/preferences.cpp	2008-08-21 23:10:31.000000000 +0400
@@ -175,10 +175,7 @@
 static void default_environment_preferences(environment_preferences_data *preferences);
 static bool validate_environment_preferences(environment_preferences_data *preferences);
 
-#if 0
 static inline float log2(int x) { return std::log((float) x) / std::log(2.0); };
-static inline float exp2(int x) { return std::exp((float) x + std::log(2.0)); };
-#endif
 
 // Prototypes
 static void player_dialog(void *arg);
