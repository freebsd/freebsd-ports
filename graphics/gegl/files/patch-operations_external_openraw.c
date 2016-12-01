OR_DATA_TYPE_CFA was replaced by OR_DATA_TYPE_RAW in libopenraw-0.1.0

--- operations/external/openraw.c.orig	2016-12-01 05:57:23 UTC
+++ operations/external/openraw.c
@@ -116,7 +116,7 @@ load_buffer (GeglOperation *operation)
       goto clean_file;
     }
 
-  if(or_rawdata_format (rawdata) != OR_DATA_TYPE_CFA)
+  if(or_rawdata_format (rawdata) != OR_DATA_TYPE_RAW)
     {
       goto clean_file;
     }
