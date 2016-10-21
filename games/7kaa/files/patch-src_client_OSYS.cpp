--- src/client/OSYS.cpp.orig	2016-09-04 17:31:41 UTC
+++ src/client/OSYS.cpp
@@ -240,6 +240,8 @@ void Sys::deinit()
 
    //-------------------------------------//
 
+   deinit_directx();
+
    init_flag = 0;
 }
 //--------- End of function Sys::deinit ---------//
