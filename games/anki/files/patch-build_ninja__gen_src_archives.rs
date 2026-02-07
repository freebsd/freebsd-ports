Enable the build for FreeBSD.  Technically it would make sense to define
corresponding variables, e.g. "FreeBSDX64" for FreeBSD amd64, instead of
using the already defined variables.

The problem here is that new variables have to be defined in other places
(= "configure/src/python.rs", "ninja_gen/src/{node,python,protobuf}.rs")
and are actually mostly needed to obtain the corresponding binary
distributions for Node, Protobuf, and Python.

Since the latter is already bypassed by setting the environment variables
"{NODE,PROTOC,PYTHON,YARN}_BINARY", it makes little sense to patch the
other parts of the code for now.

It probably makes sense to have a generic variable (e.g. "Self::FreeBSD")
for all FreeBSD architectures that is used in conjunction with OFFLINE_BUILD
to allow building on FreeBSD (and preferably other BSDs) persistently.

--- build/ninja_gen/src/archives.rs.orig	2025-06-13 08:38:15 UTC
+++ build/ninja_gen/src/archives.rs
@@ -34,6 +34,8 @@ impl Platform {
         let os = std::env::consts::OS;
         let arch = std::env::consts::ARCH;
         match (os, arch) {
+            ("freebsd", "x86_64") => Self::LinuxX64,
+            ("freebsd", "aarch64") => Self::LinuxArm,
             ("linux", "x86_64") => Self::LinuxX64,
             ("linux", "aarch64") => Self::LinuxArm,
             ("macos", "x86_64") => Self::MacX64,
