--- gnat2why/get_targ.adb.orig	2014-04-10 15:20:35 UTC
+++ gnat2why/get_targ.adb
@@ -99,33 +99,6 @@ package body Get_Targ is
       return 64;
    end Get_Long_Long_Size;
 
-   --------------------
-   -- Get_Float_Size --
-   --------------------
-
-   function Get_Float_Size return Pos is
-   begin
-      return 32;
-   end Get_Float_Size;
-
-   ---------------------
-   -- Get_Double_Size --
-   ---------------------
-
-   function Get_Double_Size return Pos is
-   begin
-      return 64;
-   end Get_Double_Size;
-
-   --------------------------
-   -- Get_Long_Double_Size --
-   --------------------------
-
-   function Get_Long_Double_Size return Pos is
-   begin
-      return 96;
-   end Get_Long_Double_Size;
-
    ----------------------
    -- Get_Pointer_Size --
    ----------------------
@@ -296,4 +269,13 @@ package body Get_Targ is
       end if;
    end Width_From_Size;
 
+   ------------------------------
+   -- Get_Back_End_Config_File --
+   ------------------------------
+
+   function Get_Back_End_Config_File return String_Ptr is
+   begin
+      return null;
+   end Get_Back_End_Config_File;
+
 end Get_Targ;
