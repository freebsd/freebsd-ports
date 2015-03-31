--- src/hugin_base/lensdb/LensDB.cpp.orig	2015-03-30 06:14:16 UTC
+++ src/hugin_base/lensdb/LensDB.cpp
@@ -627,7 +627,9 @@ bool LensDB::GetDistortion(double focal,
                 break;
             case LF_DIST_MODEL_NONE:
             case LF_DIST_MODEL_POLY5:
+#if LF_VERSION_MAJOR == 0 && LF_VERSION_MINOR < 3
             case LF_DIST_MODEL_FOV1:
+#endif
             default:
                 return false;
                 break;
