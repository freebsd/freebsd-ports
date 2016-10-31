--- arduino-core/src/cc/arduino/contributions/packages/ContributionInstaller.java.orig	2016-09-21 10:09:37 UTC
+++ arduino-core/src/cc/arduino/contributions/packages/ContributionInstaller.java
@@ -281,47 +281,11 @@ public class ContributionInstaller {
   }
 
   public synchronized List<String> updateIndex(ProgressListener progressListener) throws Exception {
-    MultiStepProgress progress = new MultiStepProgress(1);
-
-    List<String> downloadedPackageIndexFilesAccumulator = new LinkedList<>();
-    downloadIndexAndSignature(progress, downloadedPackageIndexFilesAccumulator, Constants.PACKAGE_INDEX_URL, progressListener);
-
-    Set<String> packageIndexURLs = new HashSet<>();
-    String additionalURLs = PreferencesData.get(Constants.PREF_BOARDS_MANAGER_ADDITIONAL_URLS, "");
-    if (!"".equals(additionalURLs)) {
-      packageIndexURLs.addAll(Arrays.asList(additionalURLs.split(",")));
-    }
-
-    for (String packageIndexURL : packageIndexURLs) {
-      try {
-        downloadIndexAndSignature(progress, downloadedPackageIndexFilesAccumulator, packageIndexURL, progressListener);
-      } catch (Exception e) {
-        System.err.println(e.getMessage());
-      }
-    }
-
-    progress.stepDone();
-
-    return downloadedPackageIndexFilesAccumulator;
+    return new LinkedList<>();
   }
 
   private void downloadIndexAndSignature(MultiStepProgress progress, List<String> downloadedPackagedIndexFilesAccumulator, String packageIndexUrl, ProgressListener progressListener) throws Exception {
-    File packageIndex = download(progress, packageIndexUrl, progressListener);
-    downloadedPackagedIndexFilesAccumulator.add(packageIndex.getName());
-    try {
-      File packageIndexSignature = download(progress, packageIndexUrl + ".sig", progressListener);
-      boolean signatureVerified = signatureVerifier.isSigned(packageIndex);
-      if (signatureVerified) {
-        downloadedPackagedIndexFilesAccumulator.add(packageIndexSignature.getName());
-      } else {
-        downloadedPackagedIndexFilesAccumulator.remove(packageIndex.getName());
-        Files.delete(packageIndex.toPath());
-        Files.delete(packageIndexSignature.toPath());
-        System.err.println(I18n.format(tr("{0} file signature verification failed. File ignored."), packageIndexUrl));
-      }
-    } catch (Exception e) {
-      //ignore errors
-    }
+    return;
   }
 
   private File download(MultiStepProgress progress, String packageIndexUrl, ProgressListener progressListener) throws Exception {
