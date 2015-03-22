--- src/VBox/Runtime/common/dbg/dbgmodcodeview.cpp.orig	2015-03-02 10:10:00.000000000 -0500
+++ src/VBox/Runtime/common/dbg/dbgmodcodeview.cpp	2015-03-12 16:22:25.459078000 -0400
@@ -2717,7 +2717,7 @@
         {
             /* Try the executable in case it has a NBxx tail header. */
             rc2 = rtDbgModCvProbeFile(pMod, pMod->pszImgFile, enmArch);
-            if (RT_FAILURE(rc2) && (RT_SUCCESS(rc) || VERR_DBG_NO_MATCHING_INTERPRETER))
+            if (RT_FAILURE(rc2) && (RT_SUCCESS(rc) || rc == VERR_DBG_NO_MATCHING_INTERPRETER))
                 rc = rc2;
         }
     }
