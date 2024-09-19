--- pyTooling/TerminalUI/__init__.py.orig	2024-09-19 21:15:21 UTC
+++ pyTooling/TerminalUI/__init__.py
@@ -197,7 +197,7 @@ class TerminalBaseApplication(metaclass=ExtendedType, 
 		platform = Platform()
 		if platform.IsNativeWindows:
 			size = TerminalBaseApplication.__GetTerminalSizeOnWindows()
-		elif (platform.IsNativeLinux or platform.IsNativeMacOS or platform.IsMinGW32OnWindows or platform.IsMinGW64OnWindows
+		elif (platform.IsNativeLinux or platform.IsNativeFreeBSD or platform.IsNativeMacOS or platform.IsMinGW32OnWindows or platform.IsMinGW64OnWindows
 					or platform.IsUCRT64OnWindows or platform.IsCygwin32OnWindows or platform.IsClang64OnWindows):
 			size = TerminalBaseApplication.__GetTerminalSizeOnLinux()
 		else:  # pragma: no cover
