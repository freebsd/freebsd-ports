--- Setup.hs.orig	2017-06-12 17:56:05 UTC
+++ Setup.hs
@@ -54,7 +54,7 @@ installManpages :: CopyDest -> Verbosity -> PackageDes
 installManpages copyDest verbosity pkg lbi =
 	installOrdinaryFiles verbosity dstManDir =<< srcManpages
   where
-	dstManDir   = mandir (absoluteInstallDirs pkg lbi copyDest) </> "man1"
+	dstManDir   = prefix (absoluteInstallDirs pkg lbi copyDest) </> "man" </> "man1"
 	-- If mdwn2man fails, perhaps because perl is not available,
 	-- we just skip installing man pages.
 	srcManpages = zip (repeat "man") . map takeFileName . catMaybes
