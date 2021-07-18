--- source/OpenBVE/System/Program.cs.orig	2021-04-25 10:39:43 UTC
+++ source/OpenBVE/System/Program.cs
@@ -83,6 +83,8 @@ namespace OpenBve {
 			{
 				Joysticks = new JoystickManager64();	
 			}
+			// XXX: crashes with System.PlatformNotSupportedException on the same calls below unless we call it here first
+			Joysticks.RefreshJoysticks();
 			try {
 				FileSystem = FileSystem.FromCommandLineArgs(args, CurrentHost);
 				FileSystem.CreateFileSystem();
