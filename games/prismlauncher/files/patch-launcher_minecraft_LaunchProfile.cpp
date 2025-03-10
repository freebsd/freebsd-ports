# Patch taken from er2off: https://github.com/er2off/freebsd-ports
--- launcher/minecraft/LaunchProfile.cpp.orig        2023-11-27 12:45:04 UTC
+++ launcher/minecraft/LaunchProfile.cpp
@@ -344,6 +344,14 @@ void LaunchProfile::getLibraryFiles(const RuntimeConte
     jars.clear();
     nativeJars.clear();
     for (auto lib : getLibraries()) {
+#ifdef Q_OS_FREEBSD
+        // HACKHACK: use system lwjgl3 until mojang will fix it
+        QString artifact = lib->artifactId();
+        if (artifact.startsWith("lwjgl") && lib->version().startsWith("3.")) {
+            jars += "%%LOCALBASE%%/share/java/classes/lwjgl3/" + artifact + ".jar";
+            continue;
+        }
+#endif
         lib->getApplicableFiles(runtimeContext, jars, nativeJars, native32, native64, overridePath);
     }
     // NOTE: order is important here, add main jar last to the lists
