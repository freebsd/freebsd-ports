--- JuceLibraryCode/modules/juce_core/native/juce_Files_linux.cpp.orig	2024-12-21 22:21:33 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_Files_linux.cpp
@@ -35,8 +35,16 @@ bool File::isOnCDRomDrive() const
 {
     struct statfs buf;
 
+#if JUCE_BSD
+	if (statfs(getFullPathName().toUTF8(), &buf) == 0) {
+		String s(buf.f_fstypename);
+		return s.compare("cd9660") == 0 || s.compare("udf") == 0;
+	}
+	return false;
+#else
     return statfs (getFullPathName().toUTF8(), &buf) == 0
              && buf.f_type == (unsigned int) U_ISOFS_SUPER_MAGIC;
+#endif
 }
 
 bool File::isOnHardDisk() const
@@ -45,6 +53,16 @@ bool File::isOnHardDisk() const
 
     if (statfs (getFullPathName().toUTF8(), &buf) == 0)
     {
+#if JUCE_BSD
+	String s(buf.f_fstypename);
+	if (s.compare("cd9660") == 0 ||
+		s.compare("udf") == 0 ||
+		s.compare("msdosfs") == 0 ||
+		s.compare("nfs") == 0 ||
+		s.compare("smbfs") == 0) {
+		return false;
+	}
+#else
         switch (buf.f_type)
         {
             case U_ISOFS_SUPER_MAGIC:   // CD-ROM
@@ -55,6 +73,7 @@ bool File::isOnHardDisk() const
 
             default: break;
         }
+#endif
     }
 
     // Assume so if this fails for some reason
@@ -122,8 +141,8 @@ File File::getSpecialLocation (const SpecialLocationTy
         case userDesktopDirectory:            return resolveXDGFolder ("XDG_DESKTOP_DIR",   "~/Desktop");
         case userApplicationDataDirectory:    return resolveXDGFolder ("XDG_CONFIG_HOME",   "~/.config");
         case commonDocumentsDirectory:
-        case commonApplicationDataDirectory:  return File ("/opt");
-        case globalApplicationsDirectory:     return File ("/usr");
+        case commonApplicationDataDirectory:  return {};	// File ("/opt");
+        case globalApplicationsDirectory:     return {};	// File ("/usr");
 
         case tempDirectory:
         {
