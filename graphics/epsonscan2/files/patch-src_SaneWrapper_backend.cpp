--- src/SaneWrapper/backend.cpp.orig	2021-11-25 00:56:59 UTC
+++ src/SaneWrapper/backend.cpp
@@ -220,7 +220,8 @@ sane_open (SANE_String_Const device_name, SANE_Handle 
   {
     return SANE_STATUS_INVAL;
   }
-  ((Epson_Scanner*)handle)->out_buffer = NULL;
+  // XXX next causes a SEGV on FreeBSD because out_buffer is not yet allocated
+  //((Epson_Scanner*)handle)->out_buffer = NULL;
   if (!epson_backend->sane_dev)
     {
       const SANE_Device **dev = NULL;
@@ -355,6 +356,7 @@ sane_get_parameters (SANE_Handle handle, SANE_Paramete
   unsigned int nSize = 100;
   unsigned char* tmp_buf = (unsigned char*)::malloc(nSize);
   SDIChar* output_path;
+  SDIError outError = kSDIErrorNone;
   if(tmp_buf){
     memset(tmp_buf, 0, nSize);
   }else {
@@ -363,7 +365,6 @@ sane_get_parameters (SANE_Handle handle, SANE_Paramete
     goto ERROR_2;
   }
   output_path = (SDIChar*)tmp_buf;
-  SDIError outError;
   s->hw->sv->SDIImage_CreatePtr_(&s->outImageData);
   s->hw->sv->SDIScannerDriver_GetNextTransferEventPtr_(s->hw->sv->driver,
                                            &outType,
@@ -442,7 +443,7 @@ sane_get_parameters (SANE_Handle handle, SANE_Paramete
       }
     }else {
       status = SANE_STATUS_INVAL;
-      fclose(fp);
+      //fclose(fp); // shouldn't try to close file that isn't open!
       goto ERROR;
     }
     if(s->hw->sv->device_data.ColorType.select == kSDIColorTypeMono1){
