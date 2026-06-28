https://github.com/dotnet/msbuild/pull/14479

--- src/msbuild/src/Build/BackEnd/BuildManager/BuildManager.cs.orig	2026-06-26 17:46:11 UTC
+++ src/msbuild/src/Build/BackEnd/BuildManager/BuildManager.cs
@@ -2573,8 +2573,12 @@ namespace Microsoft.Build.Execution
                     }
                 }
 
-                _nodeManager!.ShutdownConnectedNodes(_buildParameters!.EnableNodeReuse);
-                _taskHostNodeManager!.ShutdownConnectedNodes(_buildParameters.EnableNodeReuse);
+                // We are aborting the build because a node exited unexpectedly.
+                // Do not reuse nodes, as their state may be compromised by attempts to shut down while the build is in-progress.
+                _nodeManager!.ShutdownConnectedNodes(false /* enableNodeReuse */);
+
+                // Do not cleanly shut down the task host nodes here because we are aborting;
+                // the task host will hear about it in time through the task building infrastructure.
 
                 foreach (BuildSubmissionBase submission in _buildSubmissions.Values)
                 {
