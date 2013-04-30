$NetBSD: patch-ada__module_core_src_ada__semantic__tree-generics.adb,v 1.1 2012/07/08 20:23:50 marino Exp $

--- ada_module/core/src/ada_semantic_tree-generics.adb.orig	2010-09-17 09:28:03.000000000 +0000
+++ ada_module/core/src/ada_semantic_tree-generics.adb
@@ -389,14 +389,12 @@ package body Ada_Semantic_Tree.Generics
       Cached : Cache_Access := Get_Cache (Info);
    begin
       if Cached /= null then
-         Result := new Declaration_View_Record'
-           (Entity          =>
-              To_Entity_Access
-                (Instanciated_Package (Cached.all).Generic_Package),
-            Generic_Context =>
+         Result := new Declaration_View_Record;
+         Declaration_View_Record (Result.all).Generic_Context :=
               To_Active
-                (Instanciated_Package (Cached.all).Generic_Context),
-            others => <>);
+                (Instanciated_Package (Cached.all).Generic_Context);
+         Result.Entity := To_Entity_Access
+           (Instanciated_Package (Cached.all).Generic_Package);
 
          Ref (Declaration_View_Record (Result.all).Generic_Context);
 
