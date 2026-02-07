--- src/runtime/src/libraries/System.Runtime/tests/System/GCTests.cs.orig	2023-11-01 21:55:24 UTC
+++ src/runtime/src/libraries/System.Runtime/tests/System/GCTests.cs
@@ -818,7 +818,6 @@ namespace System.Tests
 
         private static bool IsNotArmProcessAndRemoteExecutorSupported => PlatformDetection.IsNotArmProcess && RemoteExecutor.IsSupported;
 
-        [ActiveIssue("https://github.com/dotnet/runtime/issues/64935", TestPlatforms.FreeBSD)]
         [ActiveIssue("https://github.com/dotnet/runtime/issues/73167", TestRuntimes.Mono)]
         [ConditionalFact(nameof(IsNotArmProcessAndRemoteExecutorSupported))] // [ActiveIssue("https://github.com/dotnet/runtime/issues/29434")]
         public static void GetGCMemoryInfo()
