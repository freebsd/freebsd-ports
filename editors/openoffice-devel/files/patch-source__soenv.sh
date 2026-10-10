--- source_soenv.sh.orig	2026-09-18 00:50:45 UTC
+++ source_soenv.sh
@@ -89,7 +89,7 @@ else
         mips-*-linux*)
             . ./LinuxMIPSEnv.Set.sh
         ;;
-        i386-*-freebsd*)
+        i[3456]86-*-freebsd*)
             . ./FreeBSDX86Env.Set.sh
         ;;
         amd64-*-freebsd*|x86_64-*-freebsd*)
@@ -101,7 +101,7 @@ else
         powerpc-*-freebsd*)
             . ./FreeBSDPPCEnv.Set.sh
         ;;
-        powerpc64-*-freebsd*)
+        powerpc64-*-freebsd*|powerpc64le-*-freebsd*)
             . ./FreeBSDPPC64Env.Set.sh
         ;;
         # the result here (whether you get x86_64) seems to depend on $CC...
