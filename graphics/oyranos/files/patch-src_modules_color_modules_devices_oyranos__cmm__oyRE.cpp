Chunk 2: Fix build with libraw >= 0.21.0
Based on upstream commit:
https://gitlab.com/oyranos/oyranos/-/commit/7fd1eabdf9f59727c0f516d33663d895f812a449

--- src/modules/color/modules/devices/oyranos_cmm_oyRE.cpp.orig	2016-12-09 10:36:53 UTC
+++ src/modules/color/modules/devices/oyranos_cmm_oyRE.cpp
@@ -140,7 +140,7 @@ static int _initialised = 0;
 extern oyCMMapi8_s_ _api8;
 
 
-bool is_raw( int id );
+bool is_raw( Exiv2::ImageType id );
 int DeviceFromContext(oyConfig_s **config, libraw_output_params_t *params);
 int DeviceFromHandle_opt(oyConfig_s *device, oyOption_s *option);
 
@@ -482,7 +482,7 @@ oyProfile_s * createMatrixProfile      ( libraw_colord
       oyOptions_s * result = 0;
 
       oyOptions_SetFromInt( &opts, "///icc_profile_flags", icc_profile_flags, 0, OY_CREATE_NEW );
-      const char * reg = "//"OY_TYPE_STD"/create_profile.color_matrix.icc";
+      const char * reg = "//" OY_TYPE_STD "/create_profile.color_matrix.icc";
       oyOptions_Handle( reg, opts, "create_profile.icc_profile.color_matrix",
                         &result );
 
@@ -558,7 +558,7 @@ class exif2options {
  *
  * \todo { Untested }
  */
-int DeviceFromHandle(oyOptions_s **options, Exiv2::Image::AutoPtr image)
+int DeviceFromHandle(oyOptions_s **options, Exiv2::Image::UniquePtr image)
 {
    int error = 0;
 
@@ -1447,14 +1447,14 @@ int DeviceFromContext(oyConfig_s **config, libraw_outp
    DFC_OPT_ADD_INT_ARR(greybox,1) //4
    DFC_OPT_ADD_INT_ARR(greybox,2) //4
    DFC_OPT_ADD_INT_ARR(greybox,3) //4
-   DFC_OPT_ADD_INT(shot_select)
+   //DFC_OPT_ADD_INT(shot_select)
 
    return error;
 }
 
 int DeviceFromHandle_opt(oyConfig_s *device, oyOption_s *handle_opt)
 {
-   Exiv2::Image::AutoPtr device_handle;
+   Exiv2::Image::UniquePtr device_handle;
    oyAlloc_f allocateFunc = malloc;
    if (handle_opt) {
       char * filename = NULL;
@@ -1484,7 +1484,7 @@ int DeviceFromHandle_opt(oyConfig_s *device, oyOption_
 
       //The std::auto_ptr::get() method returns the pointer owned by the auto_ptr
       if (device_handle.get() && device_handle->good())
-         DeviceFromHandle(oyConfig_GetOptions(device,"backend_core"), device_handle);
+         DeviceFromHandle(oyConfig_GetOptions(device,"backend_core"), std::move(device_handle));
       else {
          int level = oyMSG_WARN;
          if(filename && strcmp( filename, "dummy" ) == 0)
@@ -1502,23 +1502,23 @@ int DeviceFromHandle_opt(oyConfig_s *device, oyOption_
    return 0;
 }
 
-bool is_raw( int id )
+bool is_raw( Exiv2::ImageType id )
 {
-   //using namespace Exiv2::ImageType;
+   // using namespace Exiv2::ImageType;
    switch (id) {
-      case 3: //crw:
-      case 4: //tiff
-      case 5: //mrw:
-      case 7: //cr2:
-      case 8: //raf:
-      case 9: //orf:
-      case 16: //rw2:
-         return true;
-         break;
-      default:
-         if(id == 0)
-           return false;
-         else
-           return true;
+	   case Exiv2::ImageType::crw:
+	   case Exiv2::ImageType::tiff:
+	   case Exiv2::ImageType::mrw:
+	   case Exiv2::ImageType::cr2:
+	   case Exiv2::ImageType::raf:
+	   case Exiv2::ImageType::orf:
+	   case Exiv2::ImageType::rw2:
+		   return true;
+		   break;
+	   default:
+		   if(Exiv2::ImageType::none == id)
+			   return false;
+		   else
+			   return true;
    }
 }
