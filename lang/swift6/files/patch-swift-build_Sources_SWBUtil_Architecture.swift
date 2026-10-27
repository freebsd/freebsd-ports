--- swift-build/Sources/SWBUtil/Architecture.swift.orig	2026-09-23 20:00:50 UTC
+++ swift-build/Sources/SWBUtil/Architecture.swift
@@ -105,6 +105,19 @@ public struct Architecture: Sendable {
                         return "x86_64"
                     case "arm64":
                         return "aarch64"
+                    case "powerpc":
+                        // FreeBSD utsname.machine holds the platform
+                        // ("powerpc" for every PowerPC flavor), not the CPU
+                        // architecture (MACHINE_ARCH, e.g. powerpc64le).
+                        // A native process's compile-time architecture is
+                        // the host architecture.
+                        #if arch(powerpc64le)
+                        return "powerpc64le"
+                        #elseif arch(powerpc64)
+                        return "powerpc64"
+                        #else
+                        break
+                        #endif
                     default:
                         break
                     }
