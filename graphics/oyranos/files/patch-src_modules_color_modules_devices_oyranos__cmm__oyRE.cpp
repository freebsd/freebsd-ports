--- src/modules/color/modules/devices/oyranos_cmm_oyRE.cpp.orig	2018-01-15 20:16:42 UTC
+++ src/modules/color/modules/devices/oyranos_cmm_oyRE.cpp
@@ -482,7 +482,7 @@ oyProfile_s * createMatrixProfile      ( libraw_colord
       oyOptions_s * result = 0;
 
       oyOptions_SetFromInt( &opts, "///icc_profile_flags", icc_profile_flags, 0, OY_CREATE_NEW );
-      const char * reg = "//"OY_TYPE_STD"/create_profile.color_matrix.icc";
+      const char * reg = "//" OY_TYPE_STD "/create_profile.color_matrix.icc";
       oyOptions_Handle( reg, opts, "create_profile.icc_profile.color_matrix",
                         &result );
 
