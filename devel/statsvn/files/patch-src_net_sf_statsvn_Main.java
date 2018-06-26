Skip SVN version check which doesn't work anymore with SVN 1.10.0

--- src/net/sf/statsvn/Main.java.orig	2018-06-25 06:52:30 UTC
+++ src/net/sf/statsvn/Main.java
@@ -105,12 +105,6 @@ public final class Main {
     public static void generate() {
         try {
             RepositoryFileManager manager = createRepoManager();
-            String version = manager.getProcessor().getVersionProcessor().checkSvnVersionSufficient();
-            final boolean isNewerDiffPossible = manager.getProcessor().getVersionProcessor().checkDiffPerRevPossible(version);
-            // fall-back to older option.
-            if (!isNewerDiffPossible) {
-                SvnConfigurationOptions.setLegacyDiff(true);
-            }
 
             manager.getProcessor().getInfoProcessor().checkRepoRootAvailable();
             generateDefaultHTMLSuite(manager);
