--- swift-build/Sources/SWBUtil/Architecture.swift.orig	2026-10-11 19:59:42 UTC
+++ swift-build/Sources/SWBUtil/Architecture.swift	2026-10-11 19:59:42 UTC
@@ -105,6 +105,19 @@
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
