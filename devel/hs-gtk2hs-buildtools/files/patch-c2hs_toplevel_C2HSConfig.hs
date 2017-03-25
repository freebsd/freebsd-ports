Hide the scary c11 features from c2hs, which does not understand them:

c2hs: C header contains errors:
/usr/include/sys/_types.h:104: (column 61) [ERROR]  >>> Syntax error !
  The symbol `long' does not fit here.
*** Error code 1

--- c2hs/toplevel/C2HSConfig.hs.orig	2017-03-21 18:17:37 UTC
+++ c2hs/toplevel/C2HSConfig.hs
@@ -64,14 +64,17 @@ cpp  = case os of
 -- * `-x c' forces CPP to regard the input as C code; this option seems to be
 --   understood at least on Linux, FreeBSD, and Solaris and seems to make a
 --   difference over the default language setting on FreeBSD
+--
+-- * Pass -std=c99 as c2hs get's confused by the c11 parts in the FreeBSD
+--   system headers.
 --
 -- * `-P' would suppress `#line' directives
 --
 cppopts :: [String]
 cppopts  = case (os,cpp) of
   ("openbsd","cpp") -> ["-xc", "-w"]
-  (_,"cpp")         -> ["-x", "c", "-w"]
-  (_,"gcc")         -> ["-E", "-x", "c", "-w"]
+  (_,"cpp")         -> ["-x", "c", "-w", "-std=c99"]
+  (_,"gcc")         -> ["-E", "-x", "c", "-w", "-std=c99"]
   _                 -> []

 -- C preprocessor option for including only definitions (EXPORTED)
