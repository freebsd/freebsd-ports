- from Bug 265342 - audio/dexed: fix build on armv7 arm64

--- Source/PluginData.cpp.orig	2022-07-20 04:30:35 UTC
+++ Source/PluginData.cpp
@@ -103,18 +103,14 @@ void Cartridge::packProgram(uint8_t *src, int idx, Str
  * This function normalize data that comes from corrupted sysex.
  * It used to avoid engine crashing upon extreme values
  */
-char normparm(char value, char max, int id) {
-    if ( value <= max && value >= 0 )
+uint8_t normparm(uint8_t value, uint8_t max, int id) {
+    if ( value <= max )
         return value;
     
     // if this is beyond the max, we expect a 0-255 range, normalize this
     // to the expected return value; and this value as a random data.
     
-    value = abs(value);
-    
-    char v = ((float)value)/255 * max;
-
-    return v;
+    return ((float)value)/255 * max;
 }
 
 void Cartridge::unpackProgram(uint8_t *unpackPgm, int idx) {
