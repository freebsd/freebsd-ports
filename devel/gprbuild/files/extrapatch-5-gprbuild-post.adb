--- src/gprbuild-post_compile.adb.orig	2014-04-17 09:50:17 UTC
+++ src/gprbuild-post_compile.adb
@@ -2558,6 +2558,7 @@ package body Gprbuild.Post_Compile is
                if Main_Source.Language.Name = B_Data.Language.Name then
                   Queue.Insert
                     (Source => (Format => Format_Gprbuild,
+                                Closure => False,
                                 Tree   => Main_File.Tree,
                                 Id     => Main_File.Source));
                end if;
@@ -2567,6 +2568,7 @@ package body Gprbuild.Post_Compile is
                while Roots /= null loop
                   Queue.Insert
                     (Source => (Format => Format_Gprbuild,
+                                Closure => False,
                                 Tree   => Main_File.Tree,
                                 Id     => Roots.Root));
                   Roots := Roots.Next;
@@ -2627,6 +2629,7 @@ package body Gprbuild.Post_Compile is
 
                         Queue.Insert
                           (Source => (Format => Format_Gprbuild,
+                                      Closure => False,
                                       Tree   => Main_File.Tree,
                                       Id     => Source));
                      end if;
