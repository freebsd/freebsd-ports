--- ncurses-0.2.16/lib/UI/NCurses/Enums.chs.orig	2016-08-29 01:09:37 UTC
+++ ncurses-0.2.16/lib/UI/NCurses/Enums.chs
@@ -41,7 +41,7 @@ class Enum a where
 	pred, succ :: a -> a
 	pred = error "ncurses Enum: pred"
 	succ = error "ncurses Enum: succ"
-	
+
 	enumFrom :: a -> [a]
 	enumFrom = error "ncurses Enum: enumFrom"
 	enumFromThen :: a -> a -> [a]
@@ -195,7 +195,6 @@ enum hsncurses_Key
 , hsncurses_KEY_UNDO = KEY_UNDO
 , hsncurses_KEY_MOUSE = KEY_MOUSE
 , hsncurses_KEY_RESIZE = KEY_RESIZE
-, hsncurses_KEY_EVENT = KEY_EVENT
 };
 #endc
 
