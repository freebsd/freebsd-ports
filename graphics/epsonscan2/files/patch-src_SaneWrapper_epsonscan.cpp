--- src/SaneWrapper/epsonscan.cpp.orig	2024-09-12 07:10:44 UTC
+++ src/SaneWrapper/epsonscan.cpp
@@ -144,7 +144,7 @@ memset(&dev->devInfo, 0, sizeof(SDIDeviceInfo));
   char* nameToTok = (char*)malloc(strlen(name) + 1);
   strcpy(nameToTok, name);
   char* dislayname = strtok(nameToTok, ":");
-  char* serialNumber = NULL;;
+  const char* serialNumber = NULL;;
   char temp_displayName[50];
   bool serialNumberSkipped = false;
   memcpy(temp_displayName, dislayname, min(sizeof(temp_displayName), strlen(dislayname) + 1));
@@ -907,7 +907,7 @@ sane_start (SANE_Handle handle)
     select_current_doc_size(s, s->hw->sv->device_data);
     handle_scan_area (s, (char *) s->hw->cur_doc_size);
   }
-  if(sane_app_compatible("simple-scan")){
+  if(sane_app_compatible((SANE_String)"simple-scan")){
     double max_x = s->hw->sv->device_data.ScanArea.MaxScanAreaWidth.select / 100.0 * s->hw->sv->device_data.Resolution.select;
     double max_y = s->hw->sv->device_data.ScanArea.MaxScanAreaHeight.select / 100.0 * s->hw->sv->device_data.Resolution.select;
     if(max_x <= s->hw->sv->device_data.ScanArea.ScanAreaWidth.select &&
@@ -1359,7 +1359,7 @@ set_epson_value (Epson_Scanner *s, SANE_Int option, vo
         gamma_range.min) != SANE_STATUS_GOOD){
         return SANE_STATUS_INVAL;
       }
-      SANE_TRACE_LOG("gamma = %d", value);
+      SANE_TRACE_LOG("gamma = %d", *((SANE_Word *)value));
       handle_gamma (s, (SANE_UNFIX(*((SANE_Int *) value))*10));
       break;
     case OPT_MODE:
@@ -1379,7 +1379,7 @@ set_epson_value (Epson_Scanner *s, SANE_Int option, vo
         brightness_range.min) != SANE_STATUS_GOOD){
         return SANE_STATUS_INVAL;
       }
-      SANE_TRACE_LOG("brightne = %d", value);
+      SANE_TRACE_LOG("brightne = %d", *((SANE_Word *)value));
       handle_brightness (s, *((SANE_Word *) value));
       break;
     case OPT_CONTRAST:
