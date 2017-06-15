--- arduino-core/src/cc/arduino/contributions/libraries/LibraryInstaller.java.orig	2016-09-21 10:09:37 UTC
+++ arduino-core/src/cc/arduino/contributions/libraries/LibraryInstaller.java
@@ -55,31 +55,7 @@ public class LibraryInstaller {
   }
 
   public synchronized void updateIndex(ProgressListener progressListener) throws Exception {
-    final MultiStepProgress progress = new MultiStepProgress(2);
-
-    DownloadableContributionsDownloader downloader = new DownloadableContributionsDownloader(BaseNoGui.librariesIndexer.getStagingFolder());
-    // Step 1: Download index
-    File outputFile = BaseNoGui.librariesIndexer.getIndexFile();
-    File tmpFile = new File(outputFile.getAbsolutePath() + ".tmp");
-    try {
-      GZippedJsonDownloader gZippedJsonDownloader = new GZippedJsonDownloader(downloader, new URL(Constants.LIBRARY_INDEX_URL), new URL(Constants.LIBRARY_INDEX_URL_GZ));
-      gZippedJsonDownloader.download(tmpFile, progress, tr("Downloading libraries index..."), progressListener);
-    } catch (InterruptedException e) {
-      // Download interrupted... just exit
-      return;
-    }
-    progress.stepDone();
-
-    // TODO: Check downloaded index
-
-    // Replace old index with the updated one
-    if (outputFile.exists())
-      outputFile.delete();
-    if (!tmpFile.renameTo(outputFile))
-      throw new Exception(tr("An error occurred while updating libraries index!"));
-
-    // Step 2: Rescan index
-    rescanLibraryIndex(progress, progressListener);
+    return;
   }
 
   public synchronized void install(ContributedLibrary lib, ContributedLibrary replacedLib, ProgressListener progressListener) throws Exception {
