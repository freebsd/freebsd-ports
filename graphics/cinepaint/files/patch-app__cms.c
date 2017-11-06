--- app/cms.c.orig
+++ app/cms.c
@@ -37,17 +37,11 @@
 #endif
 
 #ifdef HAVE_OY
-#include <oyranos/oyranos.h>
-#ifndef OYRANOS_VERSION
-#define OYRANOS_VERSION 0
+#include <oyranos_conversion.h>
+#include <oyranos_devices.h>
+#include <oyObject_s.h>
+#include <oyProfiles_s.h>
 #endif
-#if OYRANOS_VERSION < 108
-#include <arpa/inet.h>  /* ntohl */
-#include <oyranos/oyranos_monitor.h>
-#else
-#include <oyranos/oyranos_alpha.h>
-#endif
-#endif
 
 #include "config.h"
 #include "../lib/version.h"
@@ -114,7 +108,7 @@
     cmsHPROFILE handle;
     char       *data;                   /* save original data for profile i/o */
     size_t      size;
-    char        cspace[8];
+    const char *cspace;
 };
 
 /* same for transform */
@@ -348,7 +342,7 @@
 
 #ifdef HAVE_OY
 # if OYRANOS_VERSION > 107
-int iccMessageFunc( int code, const oyStruct_s * context, const char * format, ... )
+int iccMessageFunc( int code, const oyPointer * context, const char * format, ... )
 {
   char* text = 0, *pos = 0;
   va_list list;
@@ -359,10 +353,10 @@
     return 0;
 
 
-  if(context && oyOBJECT_NONE < context->type_)
+  if(context && oyOBJECT_NONE < ((oyStruct_s*)context)->type_)
   {
-    type_name = oyStruct_TypeToText( context );
-    id = oyObject_GetId( context->oy_ );
+    type_name = oyStruct_TypeToText( (oyStruct_s*)context );
+    id = oyObject_GetId( ((oyStruct_s*)context)->oy_ );
   }
 
   text = (char*)calloc(sizeof(char), 4096);
@@ -463,7 +457,7 @@
       const char *display_name = gdk_get_display ();
 
       test = oyGetMonitorProfile( display_name, &test_size, my_alloc_func );
-      printf("%s:%d %s() monitor profile size: %d\n",__FILE__,__LINE__,__func__,
+      printf("%s:%d %s() monitor profile size: %lu\n",__FILE__,__LINE__,__func__,
               test_size );
 
       if (test == NULL || !test_size)
@@ -566,36 +560,36 @@
 
 const char* 
 cms_get_color_space_name (cmsHPROFILE hProfile)
-{   static gchar name[10];
+{   static char *name = 10;
 
     switch (cmsGetColorSpace (hProfile))
     {
-        case icSigXYZData: sprintf(name, _("XYZ")); break;
-        case icSigLabData: sprintf(name, _("Lab")); break;
-        case icSigLuvData: sprintf(name, _("Luv")); break;
-        case icSigYCbCrData: sprintf(name, _("YCbCr")); break;
-        case icSigYxyData: sprintf(name, _("Yxy")); break;
-        case icSigRgbData: sprintf(name, _("Rgb")); break;
-        case icSigGrayData: sprintf(name, _("Gray")); break;
-        case icSigHsvData: sprintf(name, _("Hsv")); break;
-        case icSigHlsData: sprintf(name, _("Hls")); break;
-        case icSigCmykData: sprintf(name, _("Cmyk")); break;
-        case icSigCmyData: sprintf(name, _("Cmy")); break;
-        case icSig2colorData: sprintf(name, _("2color")); break;
-        case icSig3colorData: sprintf(name, _("3color")); break;
-        case icSig4colorData: sprintf(name, _("4color")); break;
-        case icSig5colorData: sprintf(name, _("5color")); break;
-        case icSig6colorData: sprintf(name, _("6color")); break;
-        case icSig7colorData: sprintf(name, _("7color")); break;
-        case icSig8colorData: sprintf(name, _("8color")); break;
-        case icSig9colorData: sprintf(name, _("9color")); break;
-        case icSig10colorData: sprintf(name, _("10color")); break;
-        case icSig11colorData: sprintf(name, _("11color")); break;
-        case icSig12colorData: sprintf(name, _("12color")); break;
-        case icSig13colorData: sprintf(name, _("13color")); break;
-        case icSig14colorData: sprintf(name, _("14color")); break;
-        case icSig15colorData: sprintf(name, _("15color")); break;
-        default: name[0] = '\0';
+        case icSigXYZData: name = _("XYZ"); break;
+        case icSigLabData: name = _("Lab"); break;
+        case icSigLuvData: name = _("Luv"); break;
+        case icSigYCbCrData: name = _("YCbCr"); break;
+        case icSigYxyData: name = _("Yxy"); break;
+        case icSigRgbData: name = _("Rgb"); break;
+        case icSigGrayData: name = _("Gray"); break;
+        case icSigHsvData: name = _("Hsv"); break;
+        case icSigHlsData: name = _("Hls"); break;
+        case icSigCmykData: name = _("Cmyk"); break;
+        case icSigCmyData: name = _("Cmy"); break;
+        case icSig2colorData: name = _("2color"); break;
+        case icSig3colorData: name = _("3color"); break;
+        case icSig4colorData: name = _("4color"); break;
+        case icSig5colorData: name = _("5color"); break;
+        case icSig6colorData: name = _("6color"); break;
+        case icSig7colorData: name = _("7color"); break;
+        case icSig8colorData: name = _("8color"); break;
+        case icSig9colorData: name = _("9color"); break;
+        case icSig10colorData: name = _("10color"); break;
+        case icSig11colorData: name = _("11color"); break;
+        case icSig12colorData: name = _("12color"); break;
+        case icSig13colorData: name = _("13color"); break;
+        case icSig14colorData: name = _("14color"); break;
+        case icSig15colorData: name = _("15color"); break;
+        default: name = "";
     }
 
     return name;
@@ -603,17 +597,16 @@
 
 const char**
 cms_get_color_space_channel_names (cmsHPROFILE hProfile)
-{   static char** name = 0;
+{   static char* name[5] = {0,0,0,0,0};
     const char** ret = 0;
-    if(!name)
+    if(!name[0])
     { int i;
-      name=(char**)calloc(sizeof(char**),4);
       for(i = 0; i < 4; ++i)
-        name[i] = (char*)calloc(sizeof(char*),36);
+        name[i] = (char*)calloc(sizeof(char),128);
     }
+    sprintf(name[0], "---");
     sprintf(name[1], "---");
     sprintf(name[2], "---");
-    sprintf(name[3], "---");
 
     ret = (const char**) name;
     sprintf( name[3],_("Alpha"));
@@ -683,7 +676,7 @@
 
 const char*
 cms_get_device_class_name (cmsHPROFILE hProfile)
-{   static char class[15];
+{   static char class[128];
 
     switch (cmsGetDeviceClass (hProfile))
     {
@@ -939,13 +932,16 @@
 #ifdef HAVE_OY
     if(cms_oyranos)
     {
-# if OYRANOS_VERSION > 107
+# if OYRANOS_VERSION > 905
       oyPROFILE_e type = oyDEFAULT_PROFILE_START;
       int size, i;
       oyProfile_s * temp_prof = 0;
       oyProfiles_s * iccs = 0;
+      uint32_t icc_profile_flags =oyICCProfileSelectionFlagsFromOptions(
+                                      OY_CMM_STD, "//" OY_TYPE_STD "/icc_color",
+                                                                     NULL, 0 );
 
-      iccs = oyProfiles_ForStd( type, 0, 0 );
+      iccs = oyProfiles_ForStd( type, icc_profile_flags, 0, 0 );
 
       size = oyProfiles_Count( iccs );
       for( i = 0; i < size; ++i)
@@ -1193,6 +1189,8 @@
  */
 const char * cms_get_profile_cspace ( CMSProfile         * profile )
 {
+  if(!profile->cspace)
+    return "";
   return profile->cspace;
 }
 
@@ -1222,22 +1220,21 @@
 #ifdef HAVE_OY
     if ( profile == NULL )
     {
+      char *pp_name = NULL;
       /* add path to non pathnamed file names */
       if(file_name && !strchr(file_name, OY_SLASH_C))
       {
-        char *pp_name = oyGetPathFromProfileName( file_name, my_alloc_func );
+        pp_name = oyGetPathFromProfileName( file_name, my_alloc_func );
 
         if(pp_name && strlen(pp_name))
         {
           fullFileName = (char*) calloc (MAX_PATH, sizeof(char));;
           sprintf(fullFileName, "%s%s%s", pp_name, OY_SLASH, file_name);;
         }
-        if(pp_name) free(pp_name);
       } else
       /* catch non correct paths */
       if(file_name && strchr(file_name, OY_SLASH_C))
       {
-        char *pp_name = NULL;
         char *ptr = NULL;
 
         ptr = strrchr(file_name, OY_SLASH_C);
@@ -1251,12 +1248,13 @@
             fullFileName = (char*) calloc (MAX_PATH, sizeof(char));;
             sprintf(fullFileName, "%s%s%s", pp_name, OY_SLASH, ptr);;
           }
-          if(pp_name) free(pp_name);
         }
       }
 
       /* give lcms */
-      profile = cmsOpenProfileFromFile (fullFileName, "r");
+      if (pp_name);
+        profile = cmsOpenProfileFromFile (fullFileName, "r");
+      if (pp_name) free(pp_name);
     }
 #endif
 
@@ -1282,8 +1280,7 @@
     return_value = g_new(CMSProfile, 1);
     return_value->cache_key = strdup(cms_get_profile_keyname(profile,mem));
     return_value->handle = profile;
-    sprintf( return_value->cspace,
-             cms_get_color_space_name( return_value->handle ) );
+    return_value->cspace = cms_get_color_space_name( return_value->handle );
 
     /* save an copy of the original icc profile to mem */
     return_value->size = 0;
@@ -1336,8 +1333,7 @@
     return_value = g_new(CMSProfile, 1);
     return_value->cache_key = strdup(cms_get_profile_keyname(profile,mem_pointer));
     return_value->handle = profile;
-    sprintf( return_value->cspace,
-             cms_get_color_space_name( return_value->handle ) );
+    return_value->cspace = cms_get_color_space_name( return_value->handle );
 
     cache_entry = g_new(ProfileCacheEntry, 1);
     cache_entry->ref_count = 1;
@@ -2689,7 +2685,7 @@
 
     GSList *profile_file_names = 0;
     GSList *iterator = 0;
-    gchar *current_filename;
+    gchar *current_long_fname;
     CMSProfile *current_profile;
     CMSProfileInfo *current_profile_info;      
     int pos = can_select_none ? 1 : 0, select_pos = -1;
@@ -2720,16 +2716,20 @@
 
     while (iterator != NULL)
     {
-        current_filename = iterator->data;
-        current_profile = cms_get_profile_from_file(current_filename);
+        const char *file_name;
+        current_long_fname = iterator->data;
+        file_name = current_long_fname;
+        if(strrchr(file_name,'/'))
+          file_name = strrchr(file_name,'/') + 1;
+        current_profile = cms_get_profile_from_file(current_long_fname);
 	current_profile_info = cms_get_profile_info(current_profile);
         if(prefered_name && strlen(prefered_name) &&
-           strcmp( current_filename, prefered_name ) == 0 )
+           strcmp( file_name, prefered_name ) == 0 )
           select_pos = pos;
-        sprintf(label_text, "%s (%s)", current_profile_info->description, current_filename);
+        sprintf(label_text, "%s (%s)", current_profile_info->description, current_long_fname);
         menuitem = gtk_menu_item_new_with_label (label_text);
 	gtk_menu_append (GTK_MENU (menu), menuitem);
-	gtk_object_set_data_full(GTK_OBJECT(menuitem), "value", (gpointer)current_filename, g_free);
+	gtk_object_set_data_full(GTK_OBJECT(menuitem), "value", (gpointer)current_long_fname, g_free);
 
 	cms_return_profile(current_profile);
 
