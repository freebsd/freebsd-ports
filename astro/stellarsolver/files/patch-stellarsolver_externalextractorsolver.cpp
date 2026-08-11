--- stellarsolver/externalextractorsolver.cpp.orig	2026-06-24 17:39:22 UTC
+++ stellarsolver/externalextractorsolver.cpp
@@ -81,6 +81,18 @@ ExternalProgramPaths ExternalExtractorSolver::getDefau
             paths.watneyBinaryPath = "/opt/watney/watney-solve";
             paths.wcsPath = "/usr/bin/wcsinfo";
             break;
+        case FREEBSD_DEFAULT:
+            paths.confPath = "%%LOCALBASE%%/etc/astrometry.cfg";
+            paths.sextractorBinaryPath =  "%%LOCALBASE%%/bin/sextractor";
+            paths.solverPath = "%%LOCALBASE%%/bin/solve-field";
+            (QFile("/bin/astap").exists()) ?
+            paths.astapBinaryPath = "/bin/astap" :
+                                    paths.astapBinaryPath = "/opt/astap/astap";
+            if(QFile("%%LOCALBASE%%/bin/astap").exists())
+                paths.astapBinaryPath = "%%LOCALBASE%%/bin/astap";
+            paths.watneyBinaryPath = "/%%LOCALBASE%%/bin/watney-solve";
+            paths.wcsPath = "%%LOCALBASE%%/bin/wcsinfo";
+            break;
         case MAC_HOMEBREW:
             paths.confPath = "/usr/local/etc/astrometry.cfg";
             paths.sextractorBinaryPath = "/usr/local/bin/sex";
@@ -114,6 +126,8 @@ ExternalProgramPaths ExternalExtractorSolver::getDefau
     return getDefaultExternalPaths(MAC_HOMEBREW);
 #elif defined(Q_OS_LINUX)
     return getDefaultExternalPaths(LINUX_DEFAULT);
+#elif defined(Q_OS_FREEBSD)
+    return getDefaultExternalPaths(FREEBSD_DEFAULT);
 #else //Windows
     return getDefaultExternalPaths(WIN_ANSVR);
 #endif
