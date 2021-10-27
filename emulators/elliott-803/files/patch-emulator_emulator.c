--- emulator/emulator.c.orig	2020-11-27 12:36:20 UTC
+++ emulator/emulator.c
@@ -533,7 +533,7 @@ bool handle_key(commands_t *cmd,
         wch[0] = c;
         wch[1] = L'\0';
 
-        int x, x1, y;
+        int x, x1, y __unused;
         getyx(pads->status, y, x);
 
         waddwstr(pads->status, wch);
