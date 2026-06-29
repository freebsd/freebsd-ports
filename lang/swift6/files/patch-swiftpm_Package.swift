--- swiftpm/Package.swift.orig	2026-04-13 16:18:14 UTC
+++ swiftpm/Package.swift
@@ -1216,3 +1216,17 @@ if !shouldUseSwiftBuildFramework {
         ]
     }
 }
+
+// Skip building _InternalTestSupport if SKIP_BUILD_SWIFTPM_INTERNALTESTSUPPORT is set
+if ProcessInfo.processInfo.environment["SKIP_BUILD_SWIFTPM_INTERNALTESTSUPPORT"] != nil {
+    let targetsToOmit = ["_InternalTestSupport", "_IntegrationTestSupport", "_InternalBuildTestSupport"]
+
+    package.targets.removeAll(where: { targetsToOmit.contains($0.name) })
+
+    for i in 0..<package.targets.count {
+        package.targets[i].dependencies.removeAll(where: { dep in
+            let depName = String(describing: dep)
+            return targetsToOmit.contains(where: { depName.contains($0) })
+        })
+    }
+}
