--- src/sdlmouse.ml.orig	2011-04-10 15:33:52 UTC
+++ src/sdlmouse.ml
@@ -49,12 +49,12 @@ external cursor_data : cursor -> cursor_data
     = "ml_SDL_Cursor_data"
 
 let string_of_bits x =
-  let s = String.make 8 ' ' in
+  let s = Bytes.make 8 ' ' in
   for i=0 to 7 do
     if x land (1 lsl i) <> 0
     then s.[7-i] <- '@'
   done ;
-  s
+  Bytes.to_string s
 
 let pprint_cursor c =
   let { data = data ; mask = mask } = cursor_data c in
