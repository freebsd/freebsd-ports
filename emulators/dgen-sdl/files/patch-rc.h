Index: rc.h
@@ -16,7 +16,7 @@
 #define KEYSYM_MOD_META		0x08000000
 
 // All the CTV engine names, in string form for the RC and message bar
-extern char *ctv_names[];
+extern char const *ctv_names[];
 
 // Provide a prototype to the parse_rc function in rc.cpp
 void parse_rc(const char *file);
