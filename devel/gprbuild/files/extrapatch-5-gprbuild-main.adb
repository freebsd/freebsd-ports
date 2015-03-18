--- src/gprbuild-main.adb.orig	2014-04-17 09:50:17 UTC
+++ src/gprbuild-main.adb
@@ -182,11 +182,22 @@ procedure Gprbuild.Main is
             end if;
 
             if Is_Allowed_Language (Main_Id.Source.Language.Name) then
-               Queue.Insert
-                 (Source     => (Format => Format_Gprbuild,
-                                 Tree   => Main_Id.Tree,
-                                 Id     => Main_Id.Source),
-                  With_Roots => Builder_Data (Main_Id.Tree).Closure_Needed);
+               declare
+                  Closure : Boolean :=
+                            Builder_Data (Main_Id.Tree).Closure_Needed;
+               begin
+                  if Main_Id.Source.Language.Config.Kind /= Unit_Based
+                    and then Main_Id.Source.Roots = null
+                  then
+                     Closure := False;
+                  end if;
+                  Queue.Insert
+                    (Source     => (Format  => Format_Gprbuild,
+                                    Tree    => Main_Id.Tree,
+                                    Id      => Main_Id.Source,
+                                    Closure => Closure),
+                     With_Roots => Builder_Data (Main_Id.Tree).Closure_Needed);
+               end;
 
                --  If a non Ada main has no roots, then all sources need to be
                --  compiled, so no need to check for closure.
