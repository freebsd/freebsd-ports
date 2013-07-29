--- src/sdl/debugger.cpp.orig	2007-10-04 01:11:33.000000000 +0200
+++ src/sdl/debugger.cpp	2007-10-04 01:12:22.000000000 +0200
@@ -950,9 +950,9 @@
 {
   u32 address = 0;
   if(mem >= (u32*)&workRAM[0] && mem <= (u32*)&workRAM[0x3ffff])
-    address = 0x2000000 + ((u32)mem - (u32)&workRAM[0]);
+    address = 0x2000000 + (u32)((u8 *)mem - &workRAM[0]);
   else
-    address = 0x3000000 + ((u32)mem - (u32)&internalRAM[0]);
+    address = 0x3000000 + (u32)((u8 *)mem - &internalRAM[0]);
 
   if(size == 2)
     printf("Breakpoint (on write) address %08x old:%08x new:%08x\n", 
@@ -1389,7 +1389,7 @@
 {
   char buffer[10];
   printf("Are you sure you want to quit (y/n)? ");
-  fgets(buffer, 1024, stdin);
+  fgets(buffer, sizeof(buffer), stdin);
   
   if(buffer[0] == 'y' || buffer[0] == 'Y') {
     debugger = false;
