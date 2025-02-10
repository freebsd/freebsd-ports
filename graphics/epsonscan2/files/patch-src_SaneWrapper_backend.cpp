--- src/SaneWrapper/backend.cpp.orig	2024-09-12 07:10:44 UTC
+++ src/SaneWrapper/backend.cpp
@@ -406,6 +406,7 @@ sane_get_parameters (SANE_Handle handle, SANE_Paramete
   SANE_TRACE_LOG("--------------sane_get_parameters--------------");
   Epson_Scanner *s = (Epson_Scanner *) handle;
   SANE_Status status = SANE_STATUS_GOOD;
+  SDIError outError = kSDIErrorNone;
   int width = 0;
   int height = 0;
   if(s->scan_ready){
@@ -421,7 +422,6 @@ sane_get_parameters (SANE_Handle handle, SANE_Paramete
       goto ERROR_2;
     }
     output_path = (SDIChar*)tmp_buf;
-    SDIError outError;
     while (true)
     {
       s->hw->sv->SDIImage_CreatePtr_(&s->outImageData);
