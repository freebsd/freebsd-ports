--- gpr/src/gpr-version.ads.orig	2026-06-24 03:05:09 UTC
+++ gpr/src/gpr-version.ads
@@ -30,17 +30,17 @@ package GPR.Version is
 
 package GPR.Version is
 
-   Gpr_Version : constant String := "18.0w";
+   Gpr_Version : constant String := "%%DISTVERSION%%";
    --  Static string identifying this version
 
-   Date : constant String := "19940713";
+   Date : constant String := "%%DIST_BUILD_DATE%%";
 
    Current_Year : constant String := "2016";
 
    type Gnat_Build_Type is (Gnatpro, FSF, GPL);
    --  See Get_Gnat_Build_Type below for the meaning of these values
 
-   Build_Type : constant Gnat_Build_Type := Gnatpro;
+   Build_Type : constant Gnat_Build_Type := %%DIST_BUILD_TYPE%%;
    --  Kind of GNAT Build:
    --
    --    FSF
