$NetBSD: patch-toolchains_editor_core_src_toolchains-parsers.ads,v 1.1 2012/07/08 20:23:50 marino Exp $

--- toolchains_editor/core/src/toolchains-parsers.ads.orig	2010-09-21 08:15:41.000000000 +0000
+++ toolchains_editor/core/src/toolchains-parsers.ads
@@ -73,7 +73,7 @@ package Toolchains.Parsers is
    type Parsed_Project_Record is private;
    type Parsed_Project is access all Parsed_Project_Record;
 
-   type Project_Parser_Record is private;
+   type Project_Parser_Record is limited private;
    type Project_Parser is access all Project_Parser_Record;
 
    --------------------
@@ -184,7 +184,7 @@ private
    package Parsed_Projects_Maps is new Ada.Containers.Ordered_Maps
      (Project_Node_Id, Parsed_Project);
 
-   type Project_Parser_Record is record
+   type Project_Parser_Record is limited record
       Manager                : Toolchain_Manager;
 
       Tree_Data              : Project_Tree_Ref;
