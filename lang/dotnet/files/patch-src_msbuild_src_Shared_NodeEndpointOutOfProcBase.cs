https://github.com/dotnet/msbuild/pull/14479

--- src/msbuild/src/Shared/NodeEndpointOutOfProcBase.cs.orig	2026-06-26 17:46:11 UTC
+++ src/msbuild/src/Shared/NodeEndpointOutOfProcBase.cs
@@ -652,6 +652,15 @@ namespace Microsoft.Build.BackEnd
 #else
                                 bytesRead = localReadPipe.EndRead(result);
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
