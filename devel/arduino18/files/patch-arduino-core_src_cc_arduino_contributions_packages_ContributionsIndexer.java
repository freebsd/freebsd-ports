--- arduino-core/src/cc/arduino/contributions/packages/ContributionsIndexer.java.orig	2017-03-16 17:38:01 UTC
+++ arduino-core/src/cc/arduino/contributions/packages/ContributionsIndexer.java
@@ -86,17 +86,6 @@ public class ContributionsIndexer {
     File bundledIndexFile = new File(builtInHardwareFolder, Constants.BUNDLED_INDEX_FILE_NAME);
     mergeContributions(bundledIndexFile);
 
-    // ...and overlay the default index if present
-    File defaultIndexFile = getIndexFile(Constants.DEFAULT_INDEX_FILE_NAME);
-    if (defaultIndexFile.exists()) {
-      // Check main index signature
-      if (!PreferencesData.getBoolean("allow_insecure_packages") && !signatureVerifier.isSigned(defaultIndexFile)) {
-        throw new SignatureVerificationFailedException(Constants.DEFAULT_INDEX_FILE_NAME);
-      }
-
-      mergeContributions(defaultIndexFile);
-    }
-
     // Set main and bundled indexes as trusted
     index.getPackages().forEach(pack -> pack.setTrusted(true));
 
