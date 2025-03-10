Unixify built-in help.

--- Source/Console/Console.cpp.orig	2025-02-12 09:59:48 UTC
+++ Source/Console/Console.cpp
@@ -68,7 +68,7 @@ static void DisplayProperUsage(FILE * pFile)
 **************************************************************************************************/
 static void DisplayProperUsage(FILE * pFile)
 {
-    fwprintf(pFile, L"Proper Usage: [EXE] [Input File] [Output File] [Mode]\n\n");
+    fwprintf(pFile, L"Proper Usage: [mac] [Input File] [Output File] [Mode]\n\n");
 
     fwprintf(pFile, L"Modes: \n");
     fwprintf(pFile, L"    Compress (fast): '-c1000'\n");
@@ -85,16 +85,16 @@ static void DisplayProperUsage(FILE * pFile)
     fwprintf(pFile, L"    Convert to ID3v1 (needed by some players, etc.): '-L'\n\n");
 
     fwprintf(pFile, L"Examples:\n");
-    fwprintf(pFile, L"    Compress: mac.exe \"Metallica - One.wav\" \"Metallica - One.ape\" -c2000\n");
-    fwprintf(pFile, L"    Compress: mac.exe \"Metallica - One.wav\" \"Metallica - One.ape\" -c2000 -t \"Artist=Metallica|Album=Black|Name=One\"\n");
-    fwprintf(pFile, L"    Compress: mac.exe \"Metallica - One.wav\" auto -c2000\n");
-    fwprintf(pFile, L"    Transcode from pipe: ffmpeg.exe -i \"Metallica - One.flac\" -f wav - | mac.exe - \"Metallica - One.ape\" -c2000\n");
-    fwprintf(pFile, L"    Decompress: mac.exe \"Metallica - One.ape\" \"Metallica - One.wav\" -d\n");
-    fwprintf(pFile, L"    Decompress: mac.exe \"Metallica - One.ape\" auto -d\n");
-    fwprintf(pFile, L"    Verify: mac.exe \"Metallica - One.ape\" -v\n");
-    fwprintf(pFile, L"    Full Verify: mac.exe \"Metallica - One.ape\" -V\n");
-    fwprintf(pFile, L"    Tag: mac.exe \"Metallica - One.ape\" -t \"Artist=Metallica|Album=Black|Name=One|Comment=\\\"This is in quotes\\\"\"\n");
-    fwprintf(pFile, L"    Remove tag: mac.exe \"Metallica - One.ape\" -r\n");
+    fwprintf(pFile, L"    Compress: mac \"Metallica - One.wav\" \"Metallica - One.ape\" -c2000\n");
+    fwprintf(pFile, L"    Compress: mac \"Metallica - One.wav\" \"Metallica - One.ape\" -c2000 -t \"Artist=Metallica|Album=Black|Name=One\"\n");
+    fwprintf(pFile, L"    Compress: mac \"Metallica - One.wav\" auto -c2000\n");
+    fwprintf(pFile, L"    Transcode from pipe: ffmpeg -i \"Metallica - One.flac\" -f wav - | mac - \"Metallica - One.ape\" -c2000\n");
+    fwprintf(pFile, L"    Decompress: mac \"Metallica - One.ape\" \"Metallica - One.wav\" -d\n");
+    fwprintf(pFile, L"    Decompress: mac \"Metallica - One.ape\" auto -d\n");
+    fwprintf(pFile, L"    Verify: mac \"Metallica - One.ape\" -v\n");
+    fwprintf(pFile, L"    Full Verify: mac \"Metallica - One.ape\" -V\n");
+    fwprintf(pFile, L"    Tag: mac \"Metallica - One.ape\" -t \"Artist=Metallica|Album=Black|Name=One|Comment=\\\"This is in quotes\\\"\"\n");
+    fwprintf(pFile, L"    Remove tag: mac \"Metallica - One.ape\" -r\n");
 }
 
 /**************************************************************************************************
