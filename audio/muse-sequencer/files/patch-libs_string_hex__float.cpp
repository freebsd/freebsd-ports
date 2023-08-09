- workaround for https://github.com/muse-sequencer/muse/issues/1236

--- libs/string/hex_float.cpp.orig	2023-08-09 00:25:02 UTC
+++ libs/string/hex_float.cpp
@@ -70,6 +70,8 @@ double museStringToDouble(const QString &s, bool *ok)
   if(ok)
     *ok = true;
 
+  return value;
+
 #else // C++ istringstream does not support hexfloat
 
   // Is it a hex number?
