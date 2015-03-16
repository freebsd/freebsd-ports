--- src/gprlib.adb.orig	2014-04-17 09:50:17 UTC
+++ src/gprlib.adb
@@ -1185,12 +1185,12 @@ begin
                        new String'
                          ("-lgnat" &
                           Shared_Libgnat_Separator &
-                          Line (6 .. Last));
+                          Line (6));
                      Libgnarl :=
                        new String'
                          ("-lgnarl" &
                           Shared_Libgnat_Separator &
-                          Line (6 .. Last));
+                          Line (6));
                   end if;
 
                else
