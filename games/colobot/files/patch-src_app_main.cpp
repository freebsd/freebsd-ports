--- src/app/main.cpp
+++ src/app/main.cpp
@@ -94,10 +94,14 @@ The current layout is the following:
  - src/script - link with the CBot library
 */
 
-//! Entry point to the program
+// On *some* platforms, SDL declares a macro which renames main to SDL_main.
+// If that's the case, use "extern C" to prevent name mangling.
+#ifdef main
 extern "C"
 {
+#endif
 
+//! Entry point to the program
 int main(int argc, char *argv[])
 {
     CLogger logger; // single instance of logger
@@ -176,4 +180,6 @@ int main(int argc, char *argv[])
     return code;
 }
 
+#ifdef main
 } // extern "C"
+#endif
