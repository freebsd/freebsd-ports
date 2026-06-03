--- Utility/DirWatcher/Kqueue.hs.orig	2001-09-09 01:46:40 UTC
+++ Utility/DirWatcher/Kqueue.hs
@@ -33,9 +33,9 @@ data Change
 import Control.Concurrent
 
 data Change
-	= Deleted FilePath
-	| DeletedDir FilePath
-	| Added FilePath
+	= Deleted OsPath
+	| DeletedDir OsPath
+	| Added OsPath
 	deriving (Show)
 
 isAdd :: Change -> Bool
@@ -43,26 +43,26 @@ isAdd (DeletedDir _) = False
 isAdd (Deleted _) = False
 isAdd (DeletedDir _) = False
 
-changedFile :: Change -> FilePath
+changedFile :: Change -> OsPath
 changedFile (Added f) = f
 changedFile (Deleted f) = f
 changedFile (DeletedDir f) = f
 
 data Kqueue = Kqueue 
 	{ kqueueFd :: Fd
-	, kqueueTop :: FilePath
+	, kqueueTop :: OsPath
 	, kqueueMap :: DirMap
 	, _kqueuePruner :: Pruner
 	}
 
-type Pruner = FilePath -> Bool
+type Pruner = OsPath -> Bool
 
 type DirMap = M.Map Fd DirInfo
 
 {- Enough information to uniquely identify a file in a directory,
  - but not too much. -}
 data DirEnt = DirEnt
-	{ dirEnt :: FilePath -- relative to the parent directory
+	{ dirEnt :: OsPath -- relative to the parent directory
 	, _dirInode :: FileID -- included to notice file replacements
 	, isSubDir :: Bool
 	}
@@ -70,20 +70,20 @@ data DirInfo = DirInfo
 
 {- A directory, and its last known contents. -}
 data DirInfo = DirInfo
-	{ dirName :: FilePath
+	{ dirName :: OsPath
 	, dirCache :: S.Set DirEnt
 	}
 	deriving (Show)
 
-getDirInfo :: FilePath -> IO DirInfo
+getDirInfo :: OsPath -> IO DirInfo
 getDirInfo dir = do
-	l <- filter (not . dirCruft . toRawFilePath) <$> getDirectoryContents dir
+	l <- filter (`notElem` dirCruft) <$> getDirectoryContents dir
 	contents <- S.fromList . catMaybes <$> mapM getDirEnt l
 	return $ DirInfo dir contents
   where
 	getDirEnt f = catchMaybeIO $ do
-		s <- getSymbolicLinkStatus (dir </> f)
-		return $ DirEnt f (fileID s) (isDirectory s)
+		s <- Posix.getSymbolicLinkStatus (fromOsPath (dir </> f))
+		return $ DirEnt f (Posix.fileID s) (Posix.isDirectory s)
 
 {- Difference between the dirCaches of two DirInfos. -}
 (//) :: DirInfo -> DirInfo -> [Change]
@@ -99,7 +99,7 @@ oldc // newc = deleted ++ added
 
 {- Builds a map of directories in a tree, possibly pruning some.
  - Opens each directory in the tree, and records its current contents. -}
-scanRecursive :: FilePath -> Pruner -> IO DirMap
+scanRecursive :: OsPath -> Pruner -> IO DirMap
 scanRecursive topdir prune = M.fromList <$> walk [] [topdir]
   where
 	walk c [] = return c
@@ -111,7 +111,7 @@ scanRecursive topdir prune = M.fromList <$> walk [] [t
 				Nothing -> walk c rest
 				Just info -> do
 					mfd <- catchMaybeIO $
-						openFdWithMode (toRawFilePath dir) Posix.ReadOnly Nothing
+						openFdWithMode (fromOsPath dir) Posix.ReadOnly Nothing
 							Posix.defaultFileFlags
 							(CloseOnExecFlag True)
 					case mfd of
@@ -124,21 +124,21 @@ scanRecursive topdir prune = M.fromList <$> walk [] [t
 {- Adds a list of subdirectories (and all their children), unless pruned to a
  - directory map. Adding a subdirectory that's already in the map will
  - cause its contents to be refreshed. -}
-addSubDirs :: DirMap -> Pruner -> [FilePath] -> IO DirMap
+addSubDirs :: DirMap -> Pruner -> [OsPath] -> IO DirMap
 addSubDirs dirmap prune dirs = do
 	newmap <- foldr M.union M.empty <$>
 		mapM (\d -> scanRecursive d prune) dirs
 	return $ M.union newmap dirmap -- prefer newmap
 
 {- Removes a subdirectory (and all its children) from a directory map. -}
-removeSubDir :: DirMap -> FilePath -> IO DirMap
+removeSubDir :: DirMap -> OsPath -> IO DirMap
 removeSubDir dirmap dir = do
 	mapM_ Posix.closeFd $ M.keys toremove
 	return rest
   where
-	(toremove, rest) = M.partition (dirContains (toRawFilePath dir) . toRawFilePath . dirName) dirmap
+	(toremove, rest) = M.partition (dirContains dir . dirName) dirmap
 
-findDirContents :: DirMap -> FilePath -> [FilePath]
+findDirContents :: DirMap -> OsPath -> [OsPath]
 findDirContents dirmap dir = concatMap absolutecontents $ search
   where
 	absolutecontents i = map (dirName i </>)
@@ -154,7 +154,7 @@ foreign import ccall safe "libkqueue.h waitchange_kque
 	:: Fd -> IO Fd
 
 {- Initializes a Kqueue to watch a directory, and all its subdirectories. -}
-initKqueue :: FilePath -> Pruner -> IO Kqueue
+initKqueue :: OsPath -> Pruner -> IO Kqueue
 initKqueue dir pruned = do
 	dirmap <- scanRecursive dir pruned
 	h <- c_init_kqueue
@@ -268,4 +268,4 @@ runHooks kq hooks = do
 		Just a -> a (changedFile change) s
 
 	withstatus change a = maybe noop (a change) =<<
-		(catchMaybeIO (getSymbolicLinkStatus (changedFile change)))
+		(catchMaybeIO (Posix.getSymbolicLinkStatus (fromOsPath (changedFile change))))
