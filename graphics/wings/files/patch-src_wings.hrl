--- src/wings.hrl.orig	2015-06-24 22:08:57 UTC
+++ src/wings.hrl
@@ -113,16 +113,16 @@
 %% State and records
 %% Main state record containing all objects and other important state.
 -record(st,
-	{shapes=gb_trees:empty() :: gb_tree(),	%All visible objects
+	{shapes=gb_trees:empty() :: gb_trees:tree(),	%All visible objects
 	 selmode=face :: sel_mode(),		%Selection mode.
 	 sh=false :: boolean(),			%Smart highlighting active.
 	 sel=[],				%Current sel: [{Id,GbSet}]
-	 ssels=gb_trees:empty() :: gb_tree(),   %Saved selections:
+	 ssels=gb_trees:empty() :: gb_trees:tree(),   %Saved selections:
 
 	 %% Selection only temporary?
 	 temp_sel=none :: 'none' | {sel_mode(),boolean()},
 
-	 mat=gb_trees:empty() :: gb_tree(),	%Defined materials (GbTree).
+	 mat=gb_trees:empty() :: gb_trees:tree(),	%Defined materials (GbTree).
 	 pal=[],                                %Palette
 	 file,					%Current filename.
 	 saved=false :: 'false'  | 'true' | 'auto' | integer(),
@@ -134,7 +134,7 @@
 
 	 edge_loop=none,			%Previous edge loop.
 	 views={0,{}},				%{Current,TupleOfViews}
-	 pst=gb_trees:empty() :: gb_tree(),     %Plugin State Info
+	 pst=gb_trees:empty() :: gb_trees:tree(),     %Plugin State Info
 						%   gb_tree where key is plugin	module 
 
 	 %% Previous commands.
@@ -148,7 +148,7 @@
 
 	 %% Undo information.
 	 last_cmd=empty_scene,		        %Last command.
-	 undo=queue:new() :: queue(),		%Undo (de)queue.
+	 undo=queue:new() :: queue:queue(),	%Undo (de)queue.
 	 next_is_undo=true :: boolean(),	%State of undo/redo toggle.
 	 undone=[] :: list()		        %States that were undone.
 	}).
@@ -165,14 +165,14 @@
 						%  The GbSet contains the
 						%  object's selection.
 	 name="" :: string() | tuple(),		%Name. (AutoUV stores other things here.)
-	 es=array:new() :: array(),		%array containing edges
-	 lv=none :: 'none' | array(),	        %Left vertex attributes
-	 rv=none :: 'none' | array(),	        %Right vertex attributes,
-	 fs :: gb_tree(),		        %Faces
-	 he=gb_sets:empty() :: gb_set(),	%Hard edges
-	 vc :: array(),		                %Connection info (=incident edge)
+	 es=array:new() :: array:array(),		%array containing edges
+	 lv=none :: 'none' | array:array(),	        %Left vertex attributes
+	 rv=none :: 'none' | array:array(),	        %Right vertex attributes,
+	 fs :: gb_trees:tree(),		        %Faces
+	 he=gb_sets:empty() :: gb_sets:set(),	%Hard edges
+	 vc :: array:array(),		                %Connection info (=incident edge)
 						% for vertices.
-	 vp=array:new() :: array(),		%Vertex positions.
+	 vp=array:new() :: array:array(),		%Vertex positions.
 	 pst=gb_trees:empty(),                  %Plugin State Info, 
 						%   gb_tree where key is plugin module
 	 mat=default,				%Materials.
