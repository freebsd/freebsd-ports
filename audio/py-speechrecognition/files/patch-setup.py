--- setup.py.orig	2023-03-13 12:15:10 UTC
+++ setup.py
@@ -10,33 +10,11 @@ from distutils import log
 
 import speech_recognition
 
-FILES_TO_MARK_EXECUTABLE = ["flac-linux-x86", "flac-linux-x86_64", "flac-mac", "flac-win32.exe"]
-
-
-class InstallWithExtraSteps(install):
-    def run(self):
-        install.run(self)  # do the original install steps
-
-        # mark the FLAC executables as executable by all users (this fixes occasional issues when file permissions get messed up)
-        for output_path in self.get_outputs():
-            if os.path.basename(output_path) in FILES_TO_MARK_EXECUTABLE:
-                log.info("setting executable permissions on {}".format(output_path))
-                stat_info = os.stat(output_path)
-                os.chmod(
-                    output_path,
-                    stat_info.st_mode |
-                    stat.S_IRUSR | stat.S_IXUSR |  # owner can read/execute
-                    stat.S_IRGRP | stat.S_IXGRP |  # group can read/execute
-                    stat.S_IROTH | stat.S_IXOTH  # everyone else can read/execute
-                )
-
-
 setup(
-    name="SpeechRecognition",
+    name="speechrecognition",
     version=speech_recognition.__version__,
     packages=["speech_recognition"],
     include_package_data=True,
-    cmdclass={"install": InstallWithExtraSteps},
 
     # PyPI metadata
     author=speech_recognition.__author__,
