--- ./src/Darcs/Repository.hs.orig	2012-04-22 17:14:14.000000000 +0200
+++ ./src/Darcs/Repository.hs	2012-05-10 16:44:09.000000000 +0200
@@ -302,19 +302,19 @@
 removeMetaFiles = mapM_ (removeFile . (darcsdir </>)) .
   filter ("meta-" `isPrefixOf`) =<< getDirectoryContents darcsdir
 
-unpackBasic :: Cache -> Tar.Entries -> IO ()
+unpackBasic :: Cache -> Tar.Entries Tar.FormatError -> IO ()
 unpackBasic c x = do
   withControlMVar $ \mv -> unpackTar c (basicMetaHandler c mv) x
   removeMetaFiles
 
-unpackPatches :: Cache -> [String] -> Tar.Entries -> IO ()
+unpackPatches :: Cache -> [String] -> Tar.Entries Tar.FormatError -> IO ()
 unpackPatches c ps x = do
   withControlMVar $ \mv -> unpackTar c (patchesMetaHandler c ps mv) x
   removeMetaFiles
 
-unpackTar :: Cache -> IO () -> Tar.Entries -> IO ()
+unpackTar :: Cache -> IO () -> Tar.Entries Tar.FormatError -> IO ()
 unpackTar  _ _ Tar.Done = return ()
-unpackTar  _ _ (Tar.Fail e)= fail e
+unpackTar  _ _ (Tar.Fail e) = fail $ show e
 unpackTar c mh (Tar.Next x xs) = case Tar.entryContent x of
   Tar.NormalFile x' _ -> do
     let p = Tar.entryPath x
