--- src/SaneWrapper/epsonscan.cpp.orig	2021-11-25 00:56:59 UTC
+++ src/SaneWrapper/epsonscan.cpp
@@ -859,7 +859,7 @@ sane_start (SANE_Handle handle)
     select_current_doc_size(s, s->hw->sv->device_data);
     handle_scan_area (s, (char *) s->hw->cur_doc_size);
   }
-  if(sane_app_compatible("simple-scan")){
+  if(sane_app_compatible((SANE_String)"simple-scan")){
     double max_x = s->hw->sv->device_data.ScanArea.MaxScanAreaWidth.select / 100.0 * s->hw->sv->device_data.Resolution.select;
     double max_y = s->hw->sv->device_data.ScanArea.MaxScanAreaHeight.select / 100.0 * s->hw->sv->device_data.Resolution.select;
     if(max_x <= s->hw->sv->device_data.ScanArea.ScanAreaWidth.select &&
@@ -1265,7 +1265,7 @@ set_epson_value (Epson_Scanner *s, SANE_Int option, vo
         gamma_range.min) != SANE_STATUS_GOOD){
         return SANE_STATUS_INVAL;
       }
-      log_call("gamma = %d", value);
+      log_call("gamma = %d", *((SANE_Word *)value));
       handle_gamma (s, (SANE_UNFIX(*((SANE_Int *) value))*10));
       break;
     case OPT_MODE:
@@ -1285,7 +1285,7 @@ set_epson_value (Epson_Scanner *s, SANE_Int option, vo
         brightness_range.min) != SANE_STATUS_GOOD){
         return SANE_STATUS_INVAL;
       }
-      log_call("brightne = %d", value);
+      log_call("brightne = %d", *((SANE_Word *)value));
       handle_brightness (s, *((SANE_Word *) value));
       break;
     case OPT_CONTRAST:
