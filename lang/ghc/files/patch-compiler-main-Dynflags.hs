--- compiler/main/DynFlags.hs.orig	2012-06-06 19:10:25.000000000 +0200
+++ compiler/main/DynFlags.hs	2013-02-08 15:23:36.000000000 +0100
@@ -2390,7 +2390,7 @@
                          flag)
                 return dflags
          HscLlvm
-          | not ((arch == ArchX86_64) && (os == OSLinux || os == OSDarwin)) &&
+          | not ((arch == ArchX86_64) && (os == OSLinux || os == OSDarwin || os == OSFreeBSD)) &&
             (not opt_Static || opt_PIC)
             ->
              do addWarn ("Ignoring " ++ flag ++ " as it is incompatible with -fPIC and -dynamic on this platform")
