--- source/OpenBVE/System/Program.cs.orig	2020-11-18 18:35:26 UTC
+++ source/OpenBVE/System/Program.cs
@@ -78,6 +78,8 @@ namespace OpenBve {
 			Application.SetCompatibleTextRenderingDefault(false);
 			CurrentHost = new Host();
 			Joysticks = new JoystickManager();
+			// XXX: crashes with System.PlatformNotSupportedException on the same calls below unless we call it here first
+			Joysticks.RefreshJoysticks();
 			try {
 				FileSystem = FileSystem.FromCommandLineArgs(args);
 				FileSystem.CreateFileSystem();
