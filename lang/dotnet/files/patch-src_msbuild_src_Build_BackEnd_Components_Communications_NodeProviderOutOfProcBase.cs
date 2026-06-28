https://github.com/dotnet/msbuild/pull/14479

--- src/msbuild/src/Build/BackEnd/Components/Communications/NodeProviderOutOfProcBase.cs.orig	2026-06-26 17:46:11 UTC
+++ src/msbuild/src/Build/BackEnd/Components/Communications/NodeProviderOutOfProcBase.cs
@@ -715,7 +715,17 @@ namespace Microsoft.Build.BackEnd
                 {
                     try
                     {
-                        int bytesRead = await _pipeStream.ReadAsync(_headerByte.AsMemory(), CancellationToken.None).ConfigureAwait(false);
+                        int bytesRead = 0;
+                        while (bytesRead < _headerByte.Length)
+                        {
+                            int read = await _pipeStream.ReadAsync(_headerByte.AsMemory(bytesRead, _headerByte.Length - bytesRead), CancellationToken.None).ConfigureAwait(false);
+                            if (read == 0)
+                            {
+                                break;
+                            }
+                            bytesRead += read;
+                        }
+
                         if (!ProcessHeaderBytesRead(bytesRead))
                         {
                             return;
@@ -1004,6 +1014,16 @@ namespace Microsoft.Build.BackEnd
                         return;
                     }
 
+                    while (bytesRead > 0 && bytesRead < _headerByte.Length)
+                    {
+                        int additionalBytesRead = _pipeStream.Read(_headerByte, bytesRead, _headerByte.Length - bytesRead);
+                        if (additionalBytesRead == 0)
+                        {
+                            break;
+                        }
+                        bytesRead += additionalBytesRead;
+                    }
+
                     if (!ProcessHeaderBytesRead(bytesRead))
                     {
                         return;
@@ -1081,6 +1101,17 @@ namespace Microsoft.Build.BackEnd
                     {
                         CommunicationsUtilities.Trace(_nodeId, "Hit CLR bug #825607: called back twice on same async result; ignoring");
                         return;
+                    }
+
+                    while (bytesRead > 0 && bytesRead < _currentPacketLength)
+                    {
+                        byte[] packetData = _readBufferMemoryStream.GetBuffer();
+                        int additionalBytesRead = _pipeStream.Read(packetData, bytesRead, _currentPacketLength - bytesRead);
+                        if (additionalBytesRead == 0)
+                        {
+                            break;
+                        }
+                        bytesRead += additionalBytesRead;
                     }
 
                     if (!ProcessBodyBytesRead(bytesRead, _currentPacketLength, packetType))
