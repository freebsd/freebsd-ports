-- Recognize FreeBSD arm64/aarch64 as AArch64 during test and runtime
-- platform detection. This is needed because the upstream 9.0.0 release
-- only accepts amd64 on FreeBSD, but the ports builders report arm64.
--- pyTooling/Platform/__init__.py.orig	2026-08-20 21:49:09 UTC
+++ pyTooling/Platform/__init__.py
@@ -306,6 +306,8 @@ class Platform(metaclass=ExtendedType, singleton=True,
 			elif sys_platform.startswith("freebsd"):
 				if machine == "amd64":
 					self._platform = Platforms.FreeBSD
+				elif machine in ("aarch64", "arm64"):
+					self._platform = Platforms.OS_FreeBSD | Platforms.ENV_Native | Platforms.ARCH_AArch64
 				else:  # pragma: no cover
 					raise UnknownPlatformException(f"Unknown architecture '{machine}' for FreeBSD.")
 			else:  # pragma: no cover
@@ -366,11 +368,11 @@ class Platform(metaclass=ExtendedType, singleton=True,
 
 	@readonly
 	def IsNativeFreeBSD(self) -> bool:
-		"""Returns true, if the platform is a :term:`native` FreeBSD x86-64 platform.
+		"""Returns true, if the platform is a :term:`native` FreeBSD platform.
 
-		:returns: ``True``, if the platform is a native FreeBSD x86-64 platform.
+		:returns: ``True``, if the platform is a native FreeBSD platform.
 		"""
-		return Platforms.FreeBSD in self._platform
+		return (Platforms.OS_FreeBSD in self._platform) and (Platforms.ENV_Native in self._platform)
 
 	@readonly
 	def IsNativeMacOS(self) -> bool:
