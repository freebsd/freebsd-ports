--- src/VBox/Main/src-server/MachineImpl.cpp.orig	2013-12-18 11:10:25.000000000 -0500
+++ src/VBox/Main/src-server/MachineImpl.cpp	2014-02-20 19:17:10.000000000 -0500
@@ -2374,7 +2374,7 @@
         case 0x8:
         case 0x9:
         case 0xA:
-            AssertCompile(RT_ELEMENTS(mHWData->mCpuIdStdLeafs) == 0xB);
+            // AssertCompile(RT_ELEMENTS(mHWData->mCpuIdStdLeafs) == 0xB);
             AssertRelease(aId < RT_ELEMENTS(mHWData->mCpuIdStdLeafs));
             setModified(IsModified_MachineData);
             mHWData.backup();
@@ -2396,7 +2396,7 @@
         case 0x80000008:
         case 0x80000009:
         case 0x8000000A:
-            AssertCompile(RT_ELEMENTS(mHWData->mCpuIdExtLeafs) == 0xB);
+            // AssertCompile(RT_ELEMENTS(mHWData->mCpuIdExtLeafs) == 0xB);
             AssertRelease(aId - 0x80000000 < RT_ELEMENTS(mHWData->mCpuIdExtLeafs));
             setModified(IsModified_MachineData);
             mHWData.backup();
@@ -2436,7 +2436,7 @@
         case 0x8:
         case 0x9:
         case 0xA:
-            AssertCompile(RT_ELEMENTS(mHWData->mCpuIdStdLeafs) == 0xB);
+            // AssertCompile(RT_ELEMENTS(mHWData->mCpuIdStdLeafs) == 0xB);
             AssertRelease(aId < RT_ELEMENTS(mHWData->mCpuIdStdLeafs));
             setModified(IsModified_MachineData);
             mHWData.backup();
@@ -2455,7 +2455,7 @@
         case 0x80000008:
         case 0x80000009:
         case 0x8000000A:
-            AssertCompile(RT_ELEMENTS(mHWData->mCpuIdExtLeafs) == 0xB);
+            // AssertCompile(RT_ELEMENTS(mHWData->mCpuIdExtLeafs) == 0xB);
             AssertRelease(aId - 0x80000000 < RT_ELEMENTS(mHWData->mCpuIdExtLeafs));
             setModified(IsModified_MachineData);
             mHWData.backup();
@@ -9322,7 +9322,7 @@
         mHWData->mVideoCaptureEnabled = data.fVideoCaptureEnabled;
         for (unsigned i = 0; i < RT_ELEMENTS(mHWData->maVideoCaptureScreens); i++)
             mHWData->maVideoCaptureScreens[i] = ASMBitTest(&data.u64VideoCaptureScreens, i);
-        AssertCompile(RT_ELEMENTS(mHWData->maVideoCaptureScreens) == sizeof(data.u64VideoCaptureScreens) * 8);
+        // AssertCompile(RT_ELEMENTS(mHWData->maVideoCaptureScreens) == sizeof(data.u64VideoCaptureScreens) * 8);
         mHWData->mVideoCaptureRate = data.ulVideoCaptureRate;
         mHWData->mVideoCaptureFPS = data.ulVideoCaptureFPS;
         if (!data.strVideoCaptureFile.isEmpty())
