--- Opcodes/OSC.c.orig	2020-08-13 23:03:03 UTC
+++ Opcodes/OSC.c
@@ -477,7 +477,7 @@ static int32_t OSC_handler(const char *path, const cha
 }
 
 static int32_t OSC_handler(const char *path, const char *types,
-                       lo_arg **argv, int32_t argc, void *data, void *p)
+                       lo_arg **argv, int argc, lo_message data, void *p)
 {
     IGN(argc);  IGN(data);
     OSC_PORT  *pp = (OSC_PORT*) p;
@@ -958,7 +958,7 @@ static int32_t OSC_ahandler(const char *path, const ch
 /* ******** ARRAY VERSION **** EXPERIMENTAL *** */
 
 static int32_t OSC_ahandler(const char *path, const char *types,
-                       lo_arg **argv, int32_t argc, void *data, void *p)
+                       lo_arg **argv, int argc, lo_message data, void *p)
 {
     IGN(argc);  IGN(data);
     OSC_PORT  *pp = (OSC_PORT*) p;
