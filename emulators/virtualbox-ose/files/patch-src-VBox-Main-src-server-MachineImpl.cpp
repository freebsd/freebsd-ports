--- src/VBox/Main/src-server/MachineImpl.cpp.orig	2015-04-01 12:15:13.000000000 -0400
+++ src/VBox/Main/src-server/MachineImpl.cpp	2015-04-01 16:11:54.601620000 -0400
@@ -2299,7 +2299,7 @@
         case 0x8:
         case 0x9:
         case 0xA:
-            AssertCompile(RT_ELEMENTS(mHWData->mCpuIdStdLeafs) == 0xB);
+            // AssertCompile(RT_ELEMENTS(mHWData->mCpuIdStdLeafs) == 0xB);
             AssertRelease(aId < RT_ELEMENTS(mHWData->mCpuIdStdLeafs));
             i_setModified(IsModified_MachineData);
             mHWData.backup();
@@ -2321,7 +2321,7 @@
         case 0x80000008:
         case 0x80000009:
         case 0x8000000A:
-            AssertCompile(RT_ELEMENTS(mHWData->mCpuIdExtLeafs) == 0xB);
+            // AssertCompile(RT_ELEMENTS(mHWData->mCpuIdExtLeafs) == 0xB);
             AssertRelease(aId - 0x80000000 < RT_ELEMENTS(mHWData->mCpuIdExtLeafs));
             i_setModified(IsModified_MachineData);
             mHWData.backup();
@@ -2358,7 +2358,7 @@
         case 0x8:
         case 0x9:
         case 0xA:
-            AssertCompile(RT_ELEMENTS(mHWData->mCpuIdStdLeafs) == 0xB);
+            // AssertCompile(RT_ELEMENTS(mHWData->mCpuIdStdLeafs) == 0xB);
             AssertRelease(aId < RT_ELEMENTS(mHWData->mCpuIdStdLeafs));
             i_setModified(IsModified_MachineData);
             mHWData.backup();
@@ -2377,7 +2377,7 @@
         case 0x80000008:
         case 0x80000009:
         case 0x8000000A:
-            AssertCompile(RT_ELEMENTS(mHWData->mCpuIdExtLeafs) == 0xB);
+            // AssertCompile(RT_ELEMENTS(mHWData->mCpuIdExtLeafs) == 0xB);
             AssertRelease(aId - 0x80000000 < RT_ELEMENTS(mHWData->mCpuIdExtLeafs));
             i_setModified(IsModified_MachineData);
             mHWData.backup();
@@ -8790,7 +8790,7 @@
         mHWData->mVideoCaptureEnabled = data.fVideoCaptureEnabled;
         for (unsigned i = 0; i < RT_ELEMENTS(mHWData->maVideoCaptureScreens); ++i)
             mHWData->maVideoCaptureScreens[i] = ASMBitTest(&data.u64VideoCaptureScreens, i);
-        AssertCompile(RT_ELEMENTS(mHWData->maVideoCaptureScreens) == sizeof(data.u64VideoCaptureScreens) * 8);
+        // AssertCompile(RT_ELEMENTS(mHWData->maVideoCaptureScreens) == sizeof(data.u64VideoCaptureScreens) * 8);
         mHWData->mVideoCaptureRate = data.ulVideoCaptureRate;
         mHWData->mVideoCaptureFPS = data.ulVideoCaptureFPS;
         if (!data.strVideoCaptureFile.isEmpty())
