--- aclocal.m4.orig	2007-06-16 19:12:11.000000000 +0200
+++ aclocal.m4	2008-01-04 19:37:37.000000000 +0100
@@ -447,6 +447,20 @@
 openFd :: Int -> Maybe FDType -> FilePath -> IOMode -> Bool -> Bool -> IO Handle
 openFd fd x y z a b = GHC.Handle.openFd fd x b y z a
         ]]),
+AC_MSG_RESULT([okay])
+IMPORT_WORKAROUND([
+import qualified GHC.Handle ( fdToHandle' )
+import System.IO ( Handle, IOMode )
+import System.Posix.Internals ( FDType )
+import qualified GHC.IOBase ( FD )
+])
+CODE_WORKAROUND([[
+  {- 
+   Work around change in the GHC.Handle.fdToHandle' API.
+  -}
+openFd :: GHC.IOBase.FD -> Maybe FDType -> FilePath -> IOMode -> Bool -> Bool -> IO Handle
+openFd fd x y z a b = GHC.Handle.fdToHandle' fd x b y z a
+]]),
        AC_MSG_RESULT([failed])
        AC_MSG_ERROR([Couldnt figure out how to call GHC.Handle.openFd!])
     )
