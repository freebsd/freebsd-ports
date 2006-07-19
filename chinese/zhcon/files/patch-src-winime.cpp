--- src/winime.cpp.orig	Tue Apr 25 00:38:28 2006
+++ src/winime.cpp	Wed Jul 19 22:29:47 2006
@@ -184,6 +184,8 @@
         p++;
     while (IsGB2312_1(*p) && IsGB2312_2(*(p + 1)))
         p += 2;
+    while (IsBIG5_1(*p) && IsBIG5_2(*(p + 1)))
+        p += 2;
     return !IsHzCode1(*p);
 }
 
