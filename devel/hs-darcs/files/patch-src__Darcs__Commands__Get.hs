--- ./src/Darcs/Commands/Get.hs.orig	2013-02-06 07:07:21.000000000 +0100
+++ ./src/Darcs/Commands/Get.hs	2014-07-13 22:39:00.000000000 +0200
@@ -157,7 +157,8 @@
   copyRepo
   withRepository opts ((RepoJob $ \repository -> goToChosenVersion repository opts) :: RepoJob ())
   putInfo opts $ text "Finished getting."
-      where copyRepo =
+      where copyRepo :: IO ()
+            copyRepo =
                 withRepository opts $ RepoJob $ \repository ->
                   if formatHas HashedInventory rfsource
                    then do
