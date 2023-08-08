commit 94b3a3c6a0cfdcdbd98edce055d5c83ecb361f37
Author: acxz <17132214+acxz@users.noreply.github.com>
Date:   Thu Aug 4 20:10:53 2022 -0400

    ifndef `wxID_OSX_*` for erlang 25.0

diff --git src/wings_frame.erl src/wings_frame.erl
index f6c13c71..3ec6bb83 100644
--- src/wings_frame.erl
+++ src/wings_frame.erl
@@ -37,10 +37,18 @@
 -define(IS_SPLIT(WinProp), (element(1, WinProp) =:= split
 			    orelse element(1, WinProp) =:= split_rev)).
 
+-ifndef(wxID_OSX_HIDE).
 -define(wxID_OSX_HIDE, 5250).
+-endif.
+-ifndef(wxID_OSX_HIDEOTHERS).
 -define(wxID_OSX_HIDEOTHERS, 5251).
+-endif.
+-ifndef(wxID_OSX_SHOWALL).
 -define(wxID_OSX_SHOWALL, 5252).
+-endif.
+-ifndef(wxID_OSX_MENU_LAST).
 -define(wxID_OSX_MENU_LAST, 5255).
+-endif.
 
 %% API  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
