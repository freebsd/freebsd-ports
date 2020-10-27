--- source/OpenBVE/System/Program.cs.orig	2020-09-21 21:11:53 UTC
+++ source/OpenBVE/System/Program.cs
@@ -92,6 +92,8 @@ namespace OpenBve {
 			//Doesn't appear to, but Mono have fixed the button appearance bug
 			CurrentlyRunningOnWindows = Environment.OSVersion.Platform == PlatformID.Win32S | Environment.OSVersion.Platform == PlatformID.Win32Windows | Environment.OSVersion.Platform == PlatformID.Win32NT;
 			Joysticks = new JoystickManager();
+			// XXX: crashes with System.PlatformNotSupportedException on the same calls below unless we call it here first
+			Joysticks.RefreshJoysticks();
 			CurrentHost = new Host();
 			try {
 				FileSystem = FileSystem.FromCommandLineArgs(args);
