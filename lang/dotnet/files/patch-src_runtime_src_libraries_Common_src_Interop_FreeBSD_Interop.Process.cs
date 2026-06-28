--- src/runtime/src/libraries/Common/src/Interop/FreeBSD/Interop.Process.cs.orig	2026-07-23 16:16:59 UTC
+++ src/runtime/src/libraries/Common/src/Interop/FreeBSD/Interop.Process.cs
@@ -107,9 +107,11 @@ internal static partial class Interop
 
             ProcessInfo info;
 
-            kinfo_proc* kinfo = GetProcInfo(pid, true, out int count);
+            kinfo_proc* kinfo = null;
             try
             {
+                kinfo = GetProcInfo(pid, true, out int count);
+
                 ArgumentOutOfRangeException.ThrowIfLessThan(count, 1, nameof(pid));
 
                 var process = new ReadOnlySpan<kinfo_proc>(kinfo, count);
