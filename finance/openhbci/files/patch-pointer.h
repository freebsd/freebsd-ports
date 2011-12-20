--- src/openhbci/core/pointer.h~	2003-07-01 22:04:04.000000000 +0200
+++ src/openhbci/core/pointer.h	2011-12-20 19:35:02.781176123 +0100
@@ -758,7 +758,7 @@
                              "Bad cast",
                              u.description());
         /* otherwise create a new pointer */
-        return makePointer(u);
+        return PointerCast::makePointer(u);
     };
 
 };
