--- packmast.cpp.orig	Tue Feb 17 06:32:00 2004
+++ packmast.cpp	Tue Feb 17 06:35:56 2004
@@ -145,6 +145,8 @@
         return p;
     if ((p = func(new PackLinuxI386(f),f)) != NULL)
         return p;
+    if ((p = func(new PackFreeBSDI386(f),f)) != NULL)
+        return p;
     if ((p = func(new PackSys(f),f)) != NULL)
         return p;
     if ((p = func(new PackCom(f),f)) != NULL)
