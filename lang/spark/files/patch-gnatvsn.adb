--- gnat2why/gnat_src/gnatvsn.adb.orig	2010-12-03 04:48:56 UTC
+++ gnat2why/gnat_src/gnatvsn.adb
@@ -53,32 +53,13 @@ package body Gnatvsn is
         " FOR A PARTICULAR PURPOSE.";
    end Gnat_Free_Software;
 
-   type char_array is array (Natural range <>) of aliased Character;
-   Version_String : char_array (0 .. Ver_Len_Max - 1);
-   --  Import the C string defined in the (language-independent) source file
-   --  version.c using the zero-based convention of the C language.
-   --  The size is not the real one, which does not matter since we will
-   --  check for the nul character in Gnat_Version_String.
-   pragma Import (C, Version_String, "version_string");
-
    -------------------------
    -- Gnat_Version_String --
    -------------------------
 
    function Gnat_Version_String return String is
-      S : String (1 .. Ver_Len_Max);
-      Pos : Natural := 0;
    begin
-      loop
-         exit when Version_String (Pos) = ASCII.NUL;
-
-         S (Pos + 1) := Version_String (Pos);
-         Pos := Pos + 1;
-
-         exit when Pos = Ver_Len_Max;
-      end loop;
-
-      return S (1 .. Pos);
+      return Gnat_Static_Version_String;
    end Gnat_Version_String;
 
 end Gnatvsn;
