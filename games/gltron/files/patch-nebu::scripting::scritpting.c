--- nebu/scripting/scripting.c.orig	Fri Dec 12 18:05:55 2003
+++ nebu/scripting/scripting.c	Mon Dec 15 22:43:04 2003
@@ -169,16 +169,16 @@
   return status;
 }    
 
-void scripting_RunFile(char *name) {
+void scripting_RunFile(const char *name) {
   lua_dofile(L, name);
 }
 
-void scripting_Run(char *command) {
+void scripting_Run(const char *command) {
   /* fprintf(stderr, "[command] %s\n", command); */
   lua_dostring(L, command);
 }
 
-void scripting_RunFormat(char *format, ... ) {
+void scripting_RunFormat(const char *format, ... ) {
   char buf[4096];
   va_list ap;
   va_start(ap, format);
