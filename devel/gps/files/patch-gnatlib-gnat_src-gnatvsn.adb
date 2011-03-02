--- gnatlib/gnat_src/gnatvsn.adb.orig	2010-12-04 08:12:30 +0000
+++ gnatlib/gnat_src/gnatvsn.adb
@@ -53,27 +53,13 @@ package body Gnatvsn is
         " FOR A PARTICULAR PURPOSE.";
    end Gnat_Free_Software;
 
-   Version_String : String (1 .. Ver_Len_Max);
-   --  Import the C string defined in the (language-independent) source file
-   --  version.c.
-   --  The size is not the real one, which does not matter since we will
-   --  check for the nul character in Gnat_Version_String.
-   pragma Import (C, Version_String, "version_string");
-
    -------------------------
    -- Gnat_Version_String --
    -------------------------
 
    function Gnat_Version_String return String is
-      NUL_Pos : Positive := 1;
    begin
-      loop
-         exit when Version_String (NUL_Pos) = ASCII.NUL;
-
-         NUL_Pos := NUL_Pos + 1;
-      end loop;
-
-      return Version_String (1 .. NUL_Pos - 1);
+      return Gnat_Static_Version_String;
    end Gnat_Version_String;
 
 end Gnatvsn;
