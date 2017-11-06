Hide the scary c11 features from c2hs, which does not understand them:

c2hs: C header contains errors:
/usr/include/sys/_types.h:104: (column 61) [ERROR]  >>> Syntax error !
  The symbol `long' does not fit here.
*** Error code 1

--- c2hs/toplevel/C2HSConfig.hs.orig	2017-01-14 09:17:54 UTC
+++ c2hs/toplevel/C2HSConfig.hs
@@ -70,8 +70,8 @@ cpp  = case os of
 cppopts :: [String]
 cppopts  = case (os,cpp) of
   ("openbsd","cpp") -> ["-xc", "-w"]
-  (_,"cpp")         -> ["-x", "c", "-w"]
-  (_,"gcc")         -> ["-E", "-x", "c", "-w"]
+  (_,"cpp")         -> ["-x", "c", "-w", "-std=c99"]
+  (_,"gcc")         -> ["-E", "-x", "c", "-w", "-std=c99"]
   _                 -> []
 
 -- C preprocessor option for including only definitions (EXPORTED)
