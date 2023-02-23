--- pyTooling/Common/Platform.py.orig	2023-02-23 18:45:13 UTC
+++ pyTooling/Common/Platform.py
@@ -52,10 +52,11 @@ class Platform(metaclass=ExtendedType, singleton=True)
 		Unknown = 0
 
 		OS_Linux =   auto()        #: Operating System: Linux.
+		OS_FreeBSD = auto()        #: Operating System: FreeBSD.
 		OS_MacOS =   auto()        #: Operating System: macOS.
 		OS_Windows = auto()        #: Operating System: Windows.
 
-		OperatingSystem = OS_Linux | OS_MacOS | OS_Windows  #: Mask: Any operating system.
+		OperatingSystem = OS_Linux | OS_FreeBSD | OS_MacOS | OS_Windows  #: Mask: Any operating system.
 
 		SEP_WindowsPath =  auto()  #: Seperator: Path element seperator (e.g. for directories).
 		SEP_WindowsValue = auto()  #: Seperator: Value seperator in variables (e.g. for paths in PATH).
@@ -76,6 +77,7 @@ class Platform(metaclass=ExtendedType, singleton=True)
 		Architecture = Arch_x86 | Arch_Arm        #: Mask: Any architecture.
 
 		Linux =   OS_Linux   | ENV_Native | ARCH_x86_64                                       #: Group: native Linux on x86-64.
+		FreeBSD = OS_FreeBSD | ENV_Native | ARCH_x86_64                                       #: Group: native FreeBSD on x86-64.
 		MacOS =   OS_MacOS   | ENV_Native | ARCH_x86_64                                       #: Group: native macOS on x86-64.
 		Windows = OS_Windows | ENV_Native | ARCH_x86_64 | SEP_WindowsPath | SEP_WindowsValue  #: Group: native Windows on x86-64.
 
@@ -155,6 +157,16 @@ class Platform(metaclass=ExtendedType, singleton=True)
 					self._platform |= self.Platforms.ARCH_x86_32
 				else:
 					raise Exception(f"Unknown architecture '{sysconfig_platform}' for a native Linux.")
+
+			elif sys_platform.startswith("freebsd"):
+				self._platform |= self.Platforms.OS_FreeBSD | self.Platforms.ENV_Native
+
+				if sysconfig_platform.endswith("-amd64"):            # native FreeBSD amd64; Windows 64 + WSL
+					self._platform |= self.Platforms.ARCH_x86_64
+				elif sysconfig_platform.endswith("-aarch64"):        # native FreeBSD Aarch64
+					self._platform |= self.Platforms.ARCH_x86_32
+				else:
+					raise Exception(f"Unknown architecture '{sysconfig_platform}' for a native FreeBSD.")
 
 			elif sys_platform == "darwin":
 				self._platform |= self.Platforms.OS_MacOS | self.Platforms.ENV_Native | self.Platforms.ARCH_x86_64
