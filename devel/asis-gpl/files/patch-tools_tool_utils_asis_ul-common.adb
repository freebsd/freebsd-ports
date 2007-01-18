--- tools/tool_utils/asis_ul-common.adb.orig	Mon Jan  1 02:42:51 2007
+++ tools/tool_utils/asis_ul-common.adb	Mon Jan  1 02:45:07 2007
@@ -74,7 +74,7 @@
          if Gnatmake_Call then
             return Target & "gnatmake";
          else
-            return Target & "gcc";
+            return Target & "gnatgcc";
          end if;
 
       end if;
