--- src/runtime/src/libraries/Common/src/Interop/FreeBSD/Interop.Process.cs.orig	2026-10-22 19:21:32 UTC
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
@@ -86,6 +88,7 @@ internal static partial class Interop
                 Interop.Sys.Sysctl(sysctlName, ref pBuffer, ref bytesLength);
                 return System.Text.Encoding.UTF8.GetString(pBuffer, bytesLength - 1);
             }
+            catch(InvalidOperationException) { return string.Empty; }
             finally
             {
                 NativeMemory.Free(pBuffer);
@@ -105,18 +108,18 @@ internal static partial class Interop
             // Negative PIDs are invalid
             ArgumentOutOfRangeException.ThrowIfNegative(pid);
 
-            ProcessInfo info;
+            ProcessInfo info = new ProcessInfo();
 
-            kinfo_proc* kinfo = GetProcInfo(pid, true, out int count);
+            kinfo_proc* kinfo = null;
             try
             {
+                kinfo = GetProcInfo(pid, true, out int count);
+
                 ArgumentOutOfRangeException.ThrowIfLessThan(count, 1, nameof(pid));
 
                 var process = new ReadOnlySpan<kinfo_proc>(kinfo, count);
 
                 // Get the process information for the specified pid
-                info = new ProcessInfo();
-
                 info.ProcessName = Marshal.PtrToStringUTF8((IntPtr)kinfo->ki_comm)!;
                 info.BasePriority = kinfo->ki_nice;
                 info.VirtualBytes = (long)kinfo->ki_size;
@@ -135,6 +138,7 @@ internal static partial class Interop
                     info._threadInfoList.Add(ti);
                 }
             }
+            catch(InvalidOperationException) {}
             finally
             {
                 NativeMemory.Free(kinfo);
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
@@ -186,6 +191,7 @@ internal static partial class Interop
                     }
                 }
             }
+            catch(InvalidOperationException) {}
             finally
             {
                 NativeMemory.Free(info);
