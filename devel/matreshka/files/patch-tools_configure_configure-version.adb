--- tools/configure/configure-version.adb.orig	2026-06-27 12:11:36 UTC
+++ tools/configure/configure-version.adb
@@ -44,7 +44,7 @@ procedure Configure.Version is
 
 procedure Configure.Version is
    Version_Name  : constant Unbounded_String := +"VERSION";
-   Version_Value : constant Unbounded_String := +"23.0";
+   Version_Value : constant Unbounded_String := +"%%VERSION%%";
 
 begin
    Substitutions.Insert (Version_Name, Version_Value);
