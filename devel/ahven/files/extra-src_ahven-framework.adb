--- src/ahven-framework.adb.orig	2014-02-08 21:21:51.000000000 +0000
+++ src/ahven-framework.adb
@@ -14,6 +14,8 @@
 -- OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 --
 
+with GNAT.Traceback.Symbolic;
+with GNAT.Regpat;
 with Ada.Strings;
 with Ada.Unchecked_Deallocation;
 with Ada.Exceptions;
@@ -22,6 +24,24 @@ with Ahven.Long_AStrings;
 package body Ahven.Framework is
    use Ahven.AStrings;
 
+   -- Convert an exception into a traceback, but truncate it at the first
+   -- line matching "0x.* in ahven.framework" as this is unwanted trace.
+   function Filtered_Traceback (E : in Ada.Exceptions.Exception_Occurrence)
+   return String is
+      ftb : constant String := GNAT.Traceback.Symbolic.Symbolic_Traceback (E);
+      pat : constant String := "(0x[0-9a-f]* in ahven\.framework)";
+      reg : constant GNAT.Regpat.Pattern_Matcher := GNAT.Regpat.Compile (pat);
+      result : GNAT.Regpat.Match_Array (0 .. 1);
+      use type GNAT.Regpat.Match_Location;
+   begin
+      GNAT.Regpat.Match (reg, ftb, result);
+      if result (0) = GNAT.Regpat.No_Match then
+         return ftb;
+      else
+         return ftb (1 .. result (1).First - 2);
+      end if;
+   end Filtered_Traceback;
+
    -- A few local procedures, so we do not need to duplicate code.
    procedure Free_Test is
       new Ada.Unchecked_Deallocation (Object => Test'Class,
@@ -346,19 +366,19 @@ package body Ahven.Framework is
                Set_Status
                  (S            => TEST_FAIL,
                   Message      => Ada.Exceptions.Exception_Message (E),
-                  Long_Message => Ada.Exceptions.Exception_Information (E),
+                  Long_Message => Filtered_Traceback (E),
                   R            => Result);
             when E : Test_Skipped_Error =>
                Set_Status
                  (S            => TEST_SKIP,
                   Message      => Ada.Exceptions.Exception_Message (E),
-                  Long_Message => Ada.Exceptions.Exception_Information (E),
+                  Long_Message => Filtered_Traceback (E),
                   R            => Result);
             when E : others =>
                Set_Status
                  (S            => TEST_ERROR,
                   Message      => Ada.Exceptions.Exception_Message (E),
-                  Long_Message => Ada.Exceptions.Exception_Information (E),
+                  Long_Message => Filtered_Traceback (E),
                   R            => Result);
          end;
       end Run_A_Command;
