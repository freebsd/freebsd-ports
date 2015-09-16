--- src/wings_menu.erl.orig	2015-06-24 22:22:23 UTC
+++ src/wings_menu.erl
@@ -43,7 +43,7 @@
 	 sel=none :: 'none'|pos_integer(),	%Selected item (1..tuple_size(Menu))
 	 sel_side=left :: 'left'|'right',	%Selection on left or right.
 	 ns=[],					%Name stack.
-	 menu :: tuple(menu_item()),		%Normalized menu.
+	 menu,					%Normalized menu.
 	 timer=make_ref(),			%Active submenu timer.
 	 level=?INITIAL_LEVEL,			%Menu level.
 	 type :: 'plain'|'popup',	        %Type of menu.
