Hide the scary c11 features from c2hs, which does not understand them:

gtk2hsC2hs: Error in C header file.
/usr/include/sys/_types.h:104: (column 61) [FATAL]
  >>> Syntax error!
  The symbol `long' does not fit here.
*** Error code 1

--- src/C2HS/Config.hs.orig	2017-03-21 18:33:51 UTC
+++ src/C2HS/Config.hs
@@ -56,14 +56,17 @@ cpp  = case os of
 --   understood at least on Linux, FreeBSD, and Solaris and seems to make a
 --   difference over the default language setting on FreeBSD
 --
+-- * Pass -std=c99 as c2hs get's confused by the c11 parts in the FreeBSD
+--   system headers.
+--
 -- * @-P@ would suppress @#line@ directives
 --
 cppopts :: [String]
 cppopts  = case (os,cpp) of
   -- why is gcc different between all these platforms?
   ("openbsd","cpp") -> ["-xc"]
-  (_,"cpp")         -> ["-x", "c"]
-  (_,"gcc")         -> ["-E", "-x", "c"]
+  (_,"cpp")         -> ["-x", "c"]
+  (_,"gcc")         -> ["-E", "-x", "c"]
   _                 -> []

 -- | C2HS Library file name
