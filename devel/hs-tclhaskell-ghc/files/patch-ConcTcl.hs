--- ConcTcl.hs.orig	Wed Mar  5 11:38:45 2003
+++ ConcTcl.hs	Wed Mar  5 11:50:13 2003
@@ -1,6 +1,7 @@
 module ConcTcl where
 import TclPrimImpl
 import Concurrent
+import CVar
 import IOExts
 import IO
 import TclCompatibility
