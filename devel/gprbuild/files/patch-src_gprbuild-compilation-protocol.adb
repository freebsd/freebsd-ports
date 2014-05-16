The GNAT.Rewrite_Data package in not in FSF GNAT yet.  Use the local 2013
version which does not have the Link method.  This essentially changes
this file back to the GPRBuild 2013 version, so it should be ok.

--- src/gprbuild-compilation-protocol.adb.orig	2014-04-17 09:50:17.000000000 +0000
+++ src/gprbuild-compilation-protocol.adb
@@ -24,7 +24,7 @@ with Ada.Streams.Stream_IO;
 with Ada.Strings.Fixed;           use Ada.Strings.Fixed;
 with Ada.Strings.Maps.Constants;  use Ada.Strings.Maps;
 
-with GNAT.Rewrite_Data;
+with Rewrite_Data;
 with GNAT.String_Split;     use GNAT.String_Split;
 
 with Gnatvsn;      use Gnatvsn;
@@ -180,8 +180,6 @@ package body Gprbuild.Compilation.Protoc
          end Output;
 
       begin
-         Rewrite_Data.Link (Rewriter, Rewriter_CD'Unchecked_Access);
-
          if Dir /= "" and then not Exists (Dir) then
             Create_Directory (Dir);
          end if;
@@ -666,8 +664,6 @@ package body Gprbuild.Compilation.Protoc
       end Output;
 
    begin
-      Rewrite_Data.Link (Rewriter, Rewriter_CD'Unchecked_Access);
-
       if Exists (Path_Name) then
          Open (File, In_File, Path_Name);
 
