--- src/runtime/src/libraries/Common/src/Interop/FreeBSD/Interop.Process.cs.orig	2026-08-22 11:08:34 UTC
+++ src/runtime/src/libraries/Common/src/Interop/FreeBSD/Interop.Process.cs
@@ -33,9 +33,11 @@ internal static partial class Interop
         /// <returns>Returns a list of PIDs corresponding to all running processes</returns>
         internal static unsafe int[] ListAllPids()
         {
-            kinfo_proc* entries = GetProcInfo(0, false, out int numProcesses);
+            kinfo_proc* entries = null;
             try
             {
+                entries = GetProcInfo(0, false, out int numProcesses);
+
                 if (numProcesses <= 0)
                 {
                     throw new Win32Exception(SR.CantGetAllPids);
@@ -107,9 +109,11 @@ internal static partial class Interop
 
             ProcessInfo info;
 
-            kinfo_proc* kinfo = GetProcInfo(pid, true, out int count);
+            kinfo_proc* kinfo = null;
             try
             {
+                kinfo = GetProcInfo(pid, true, out int count);
+
                 ArgumentOutOfRangeException.ThrowIfLessThan(count, 1, nameof(pid));
 
                 var process = new ReadOnlySpan<kinfo_proc>(kinfo, count);
@@ -157,9 +161,10 @@ internal static partial class Interop
             proc_stats ret = default;
             int count;
 
-            kinfo_proc* info = GetProcInfo(pid, (tid != 0), out count);
+            kinfo_proc* info = null;
             try
             {
+                info = GetProcInfo(pid, (tid != 0), out count);
                 if (info != null && count >= 1)
                 {
                     if (tid == 0)
