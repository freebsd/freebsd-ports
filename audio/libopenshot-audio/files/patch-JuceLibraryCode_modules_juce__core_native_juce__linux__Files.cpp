--- JuceLibraryCode/modules/juce_core/native/juce_linux_Files.cpp.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_linux_Files.cpp
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
              && buf.f_type == (short) U_ISOFS_SUPER_MAGIC;
+#endif
 }
 
 bool File::isOnHardDisk() const
@@ -45,6 +53,13 @@ bool File::isOnHardDisk() const
 
     if (statfs (getFullPathName().toUTF8(), &buf) == 0)
     {
+#if JUCE_BSD
+		String s(buf.f_fstypename);
+		if (s.compare("cd9660") == 0 || s.compare("udf") == 0 ||
+			s.compare("nfs") == 0 || s.compare("smbfs") == 0) {
+			return false;
+		}
+#else
         switch (buf.f_type)
         {
             case U_ISOFS_SUPER_MAGIC:   // CD-ROM
@@ -55,6 +70,7 @@ bool File::isOnHardDisk() const
 
             default: break;
         }
+#endif
     }
 
     // Assume so if this fails for some reason
@@ -216,7 +232,7 @@ bool Process::openDocument (const String& fileName, co
         setsid();
 
         // Child process
-        execve (argv[0], (char**) argv, environ);
+        execv (argv[0], (char**) argv);
         exit (0);
     }
 
