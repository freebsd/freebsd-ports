--- bittest.lua.orig	2012-05-08 19:15:00 UTC
+++ bittest.lua
@@ -8,6 +8,10 @@ local vb = {
   0x7fffffff, 0x80000000, 0xffffffff
 }
 
+local function tostring(n)
+  return type(n) == "string" and n or string.format("%.11g", n)
+end
+
 local function cksum(name, s, r)
   local z = 0
   for i=1,#s do z = (z + string.byte(s, i)*i) % 2147483629 end
