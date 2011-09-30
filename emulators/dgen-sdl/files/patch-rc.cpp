Index: rc.cpp
@@ -14,13 +14,13 @@
 
 
 // CTV names
-char *ctv_names[NUM_CTV] = { "off", "blur", "scanline", "interlace" };
+char const *ctv_names[NUM_CTV] = { "off", "blur", "scanline", "interlace" };
 
 // The table of strings and the keysyms they map to.
 // The order is a bit weird, since this was originally a mapping for the SVGALib
 // scancodes, and I just added the SDL stuff on top of it.
 struct rc_keysym {
-  char *name;
+  char const *name;
   long keysym;
 } keysyms[] = {
   { "ESCAPE", PDK_ESCAPE },
@@ -300,7 +300,7 @@
 /* This is a table of all the RC options, the variables they affect, and the
  * functions to parse their values. */
 struct rc_field {
-  char *fieldname;
+  char const *fieldname;
   long (*parser)(const char*);
   long *variable;
 } rc_fields[] = {
