--- src/ahven-framework.adb.orig	2014-02-08 21:21:51.000000000 +0000
+++ src/ahven-framework.adb
@@ -14,6 +14,8 @@
 -- OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 --
 
+with GNAT.Traceback.Symbolic;
+use  GNAT.Traceback.Symbolic;
 with Ada.Strings;
 with Ada.Unchecked_Deallocation;
 with Ada.Exceptions;
@@ -346,19 +348,19 @@ package body Ahven.Framework is
                Set_Status
                  (S            => TEST_FAIL,
                   Message      => Ada.Exceptions.Exception_Message (E),
-                  Long_Message => Ada.Exceptions.Exception_Information (E),
+                  Long_Message => Symbolic_Traceback (E),
                   R            => Result);
             when E : Test_Skipped_Error =>
                Set_Status
                  (S            => TEST_SKIP,
                   Message      => Ada.Exceptions.Exception_Message (E),
-                  Long_Message => Ada.Exceptions.Exception_Information (E),
+                  Long_Message => Symbolic_Traceback (E),
                   R            => Result);
             when E : others =>
                Set_Status
                  (S            => TEST_ERROR,
                   Message      => Ada.Exceptions.Exception_Message (E),
-                  Long_Message => Ada.Exceptions.Exception_Information (E),
+                  Long_Message => Symbolic_Traceback (E),
                   R            => Result);
          end;
       end Run_A_Command;
