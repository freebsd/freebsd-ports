--- src/target.cpp.orig	2007-08-03 14:40:26.000000000 +0200
+++ src/target.cpp	2007-08-03 14:41:39.000000000 +0200
@@ -186,9 +186,9 @@
             print(238, row, COLOR_YELLOW, "%20s", "VPB file ID");
             row += 7;
             print(238, row, COLOR_YELLOW, "      %03X-%07X/%02X", 
-                        ((((unsigned int)Game.SightedCharacter) * 7001337) & 0xfff),
-                        (((unsigned int)Game.SightedCharacter) * 1337357) & 0xfffffff,
-                        (((unsigned int)Game.SightedCharacter) * 70741)  & 0xff);
+                        ((((unsigned intptr_t)Game.SightedCharacter) * 7001337) & 0xfff),
+                        (((unsigned intptr_t)Game.SightedCharacter) * 1337357) & 0xfffffff,
+                        (((unsigned intptr_t)Game.SightedCharacter) * 70741)  & 0xff);
 
 
             break;
@@ -217,7 +217,7 @@
             row += 7;
             print(238, row, COLOR_YELLOW, "%20s", "Net worth");
             row += 7;
-            print(238, row, COLOR_YELLOW, "%17u KC", (((unsigned int)Game.SightedCharacter) * 1337357) % 71937);
+            print(238, row, COLOR_YELLOW, "%17u KC", (((unsigned intptr_t)Game.SightedCharacter) * 1337357) % 71937);
             break;
         case 3:
             print(238, row, COLOR_YELLOW, "%20s", "Splat.");
