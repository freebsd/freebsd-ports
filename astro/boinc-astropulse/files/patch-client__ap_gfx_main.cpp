--- ap_gfx_main.cpp	2008-07-22 00:47:52.000000000 +0200
+++ ap_gfx_main.cpp	2012-05-12 22:28:57.000000000 +0200
@@ -34,7 +34,11 @@
 
 REDUCED_ARRAY_GEN rarray;
 AP_GDATA* ap_gdata;
+#ifdef BOINC_APP_GRAPHICS
 bool nographics_flag = false;
+#else
+bool nographics_flag = true;
+#endif
 
 void update_shmem() {
 }
