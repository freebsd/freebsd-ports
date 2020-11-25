--- src/gn/args.cc.orig	2020-11-25 15:41:38 UTC
+++ src/gn/args.cc
@@ -354,7 +354,7 @@ void Args::SetSystemVarsLocked(Scope* dest) const {
     arch = kMips64;
   else if (os_arch == "s390x")
     arch = kS390X;
-  else if (os_arch == "ppc64" || os_arch == "ppc64le")
+  else if (os_arch == "ppc64" || os_arch == "ppc64le" || os_arch == "powerpc")
     // We handle the endianness inside //build/config/host_byteorder.gni.
     // This allows us to use the same toolchain as ppc64 BE
     // and specific flags are included using the host_byteorder logic.
