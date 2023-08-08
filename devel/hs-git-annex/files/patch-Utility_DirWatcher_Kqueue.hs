--- Utility/DirWatcher/Kqueue.hs.orig	2001-09-09 01:46:40 UTC
+++ Utility/DirWatcher/Kqueue.hs
@@ -81,8 +81,8 @@ getDirInfo dir = do
 	return $ DirInfo dir contents
   where
 	getDirEnt f = catchMaybeIO $ do
-		s <- getSymbolicLinkStatus (dir </> f)
-		return $ DirEnt f (fileID s) (isDirectory s)
+		s <- Posix.getSymbolicLinkStatus (dir </> f)
+		return $ DirEnt f (Posix.fileID s) (Posix.isDirectory s)
 
 {- Difference between the dirCaches of two DirInfos. -}
 (//) :: DirInfo -> DirInfo -> [Change]
@@ -265,4 +265,4 @@ runHooks kq hooks = do
 		Just a -> a (changedFile change) s
 
 	withstatus change a = maybe noop (a change) =<<
-		(catchMaybeIO (getSymbolicLinkStatus (changedFile change)))
+		(catchMaybeIO (Posix.getSymbolicLinkStatus (changedFile change)))
