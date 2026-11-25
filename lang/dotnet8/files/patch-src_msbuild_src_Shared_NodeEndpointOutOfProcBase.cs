https://github.com/dotnet/msbuild/pull/14479

--- src/msbuild/src/Shared/NodeEndpointOutOfProcBase.cs.orig	2026-10-29 18:33:34 UTC
+++ src/msbuild/src/Shared/NodeEndpointOutOfProcBase.cs
@@ -554,6 +554,15 @@ namespace Microsoft.Build.BackEnd
 #else
                                 bytesRead = readTask.Result;
 #endif
+                                while (bytesRead > 0 && bytesRead < headerByte.Length)
+                                {
+                                    int additionalBytesRead = localReadPipe.Read(headerByte, bytesRead, headerByte.Length - bytesRead);
+                                    if (additionalBytesRead == 0)
+                                    {
+                                        break;
+                                    }
+                                    bytesRead += additionalBytesRead;
+                                }
                             }
                             catch (Exception e)
                             {
