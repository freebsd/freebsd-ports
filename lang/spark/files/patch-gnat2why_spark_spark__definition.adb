--- gnat2why/spark/spark_definition.adb.orig	2014-04-10 15:20:35 UTC
+++ gnat2why/spark/spark_definition.adb
@@ -2989,6 +2989,7 @@ package body SPARK_Definition is
               Pragma_Elaborate_All                |
               Pragma_Elaborate_Body               |
               Pragma_Export                       |
+              Pragma_Extensions_Visible           |
               Pragma_Independent                  |
               Pragma_Independent_Components       |
               Pragma_Inline                       |
@@ -3022,8 +3023,10 @@ package body SPARK_Definition is
               Pragma_Async_Writers                |
               Pragma_Contract_Cases               |
               Pragma_Depends                      |
+              Pragma_Default_Initial_Condition    |
               Pragma_Effective_Reads              |
               Pragma_Effective_Writes             |
+              Pragma_Ghost                        |
               Pragma_Global                       |
               Pragma_Initializes                  |
               Pragma_Initial_Condition            |
@@ -3050,6 +3053,8 @@ package body SPARK_Definition is
               Pragma_Check_Policy                 |
               Pragma_Inline_Always                |
               Pragma_Linker_Section               |
+              Pragma_No_Elaboration_Code_All      |
+              Pragma_No_Tagged_Streams            |
               Pragma_Pure_Function                |
               Pragma_Restriction_Warnings         |
               Pragma_Style_Checks                 |
@@ -3081,7 +3086,6 @@ package body SPARK_Definition is
          when Pragma_Abort_Defer                 |
            Pragma_Allow_Integer_Address          |
            Pragma_Attribute_Definition           |
-           Pragma_AST_Entry                      |
            Pragma_C_Pass_By_Copy                 |
            Pragma_Check_Float_Overflow           |
            Pragma_Check_Name                     |
@@ -3111,7 +3115,6 @@ package body SPARK_Definition is
            Pragma_Elaboration_Checks             |
            Pragma_Eliminate                      |
            Pragma_Enable_Atomic_Synchronization  |
-           Pragma_Export_Exception               |
            Pragma_Export_Function                |
            Pragma_Export_Object                  |
            Pragma_Export_Procedure               |
@@ -3124,12 +3127,10 @@ package body SPARK_Definition is
            Pragma_Fast_Math                      |
            Pragma_Favor_Top_Level                |
            Pragma_Finalize_Storage_Only          |
-           Pragma_Float_Representation           |
            Pragma_Ident                          |
            Pragma_Implementation_Defined         |
            Pragma_Implemented                    |
            Pragma_Implicit_Packing               |
-           Pragma_Import_Exception               |
            Pragma_Import_Function                |
            Pragma_Import_Object                  |
            Pragma_Import_Procedure               |
@@ -3149,7 +3150,6 @@ package body SPARK_Definition is
            Pragma_Linker_Alias                   |
            Pragma_Linker_Constructor             |
            Pragma_Linker_Destructor              |
-           Pragma_Long_Float                     |
            Pragma_Loop_Optimize                  |
            Pragma_Machine_Attribute              |
            Pragma_Main                           |
@@ -3170,6 +3170,7 @@ package body SPARK_Definition is
            Pragma_Post_Class                     |
            Pragma_Pre                            |
            Pragma_Predicate                      |
+           Pragma_Prefix_Exception_Messages      |
            Pragma_Pre_Class                      |
            Pragma_Priority_Specific_Dispatching  |
            Pragma_Profile_Warnings               |
