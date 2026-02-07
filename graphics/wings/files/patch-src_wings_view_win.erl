--- src/wings_view_win.erl.orig	2021-10-01 22:46:16.450805000 +0200
+++ src/wings_view_win.erl	2021-10-01 22:46:38.699204000 +0200
@@ -253,6 +253,8 @@
     case os:type() of
         {_, linux} ->
             ignore;
+        {_, freebsd} ->
+            ignore;
         _ ->
             Children = [wxStaticBoxSizer:getStaticBox(LightSz), wxStaticBoxSizer:getStaticBox(CameraSz)
                        | wxWindow:getChildren(Panel)],
