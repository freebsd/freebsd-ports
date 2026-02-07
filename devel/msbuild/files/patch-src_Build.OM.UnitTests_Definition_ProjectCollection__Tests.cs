--- src/Build.OM.UnitTests/Definition/ProjectCollection_Tests.cs.orig	2018-05-02 18:19:31 UTC
+++ src/Build.OM.UnitTests/Definition/ProjectCollection_Tests.cs
@@ -1427,6 +1427,7 @@ namespace Microsoft.Build.UnitTests.OM.D
             Assert.True(dirtyRaised);
         }
 
+#if THISASSEMBLY
         /// <summary>
         /// Verifies that the <see cref="ProjectCollection.Version"/> is correct.
         /// </summary>
@@ -1442,6 +1443,7 @@ namespace Microsoft.Build.UnitTests.OM.D
             ProjectCollection.Version.Major.ShouldBe(expectedVersion.Major);
             ProjectCollection.Version.Minor.ShouldBe(expectedVersion.Minor);
         }
+#endif
 
         /// <summary>
         /// Create an empty project file and return the path
