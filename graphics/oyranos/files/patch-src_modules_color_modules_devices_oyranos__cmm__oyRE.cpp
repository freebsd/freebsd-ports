Chunk 2: Fix build with libraw >= 0.21.0
Based on upstream commit:
https://gitlab.com/oyranos/oyranos/-/commit/7fd1eabdf9f59727c0f516d33663d895f812a449

--- src/modules/color/modules/devices/oyranos_cmm_oyRE.cpp.orig	2016-12-09 10:36:53 UTC
+++ src/modules/color/modules/devices/oyranos_cmm_oyRE.cpp
@@ -482,7 +482,7 @@ oyProfile_s * createMatrixProfile      ( libraw_colord
       oyOptions_s * result = 0;
 
       oyOptions_SetFromInt( &opts, "///icc_profile_flags", icc_profile_flags, 0, OY_CREATE_NEW );
-      const char * reg = "//"OY_TYPE_STD"/create_profile.color_matrix.icc";
+      const char * reg = "//" OY_TYPE_STD "/create_profile.color_matrix.icc";
       oyOptions_Handle( reg, opts, "create_profile.icc_profile.color_matrix",
                         &result );
 
@@ -1447,7 +1447,7 @@ int DeviceFromContext(oyConfig_s **config, libraw_outp
    DFC_OPT_ADD_INT_ARR(greybox,1) //4
    DFC_OPT_ADD_INT_ARR(greybox,2) //4
    DFC_OPT_ADD_INT_ARR(greybox,3) //4
-   DFC_OPT_ADD_INT(shot_select)
+   //DFC_OPT_ADD_INT(shot_select)
 
    return error;
 }
