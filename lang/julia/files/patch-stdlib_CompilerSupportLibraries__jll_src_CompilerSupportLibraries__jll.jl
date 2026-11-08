--- stdlib/CompilerSupportLibraries_jll/src/CompilerSupportLibraries_jll.jl.orig	2026-10-25 17:06:47 UTC
+++ stdlib/CompilerSupportLibraries_jll/src/CompilerSupportLibraries_jll.jl
@@ -56,7 +56,7 @@ else
     const libssp = "@rpath/libssp.0.dylib"
 else
     const libgcc_s = "libgcc_s.so.1"
-    const libatomic = Sys.isfreebsd() ? "libatomic.so.3" : "libatomic.so.1"
+    const libatomic = "libatomic.so.1"
     if arch(HostPlatform()) ∈ ("x86_64", "i686")
         const libquadmath = "libquadmath.so.0"
     end
@@ -72,12 +72,13 @@ function __init__()
     global libgcc_s_handle = dlopen(libgcc_s)
     global libgcc_s_path = dlpath(libgcc_s_handle)
     # `libatomic` may not be present in stripped-down installations; tolerate failure.
-    global libatomic_handle = dlopen(libatomic; throw_error = false)
+    # No! actually a mismatch between libatomic.so.3 and libatomic.so.1 gives a failure
+    global libatomic_handle = something(dlopen(libatomic; throw_error = false), C_NULL)
     if libatomic_handle != C_NULL
         global libatomic_path = dlpath(libatomic_handle)
     end
     @static if @isdefined(libquadmath)
-        global libquadmath_handle = dlopen(libquadmath; throw_error = false)
+        global libquadmath_handle = something(dlopen(libquadmath; throw_error = false), C_NULL)
         if libquadmath_handle != C_NULL
             global libquadmath_path = dlpath(libquadmath_handle)
         end
