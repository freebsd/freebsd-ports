--- trackercore/loader_xm.cpp.orig	Wed Apr 24 12:33:40 2002
+++ trackercore/loader_xm.cpp	Fri Dec 27 22:44:16 2002
@@ -387,7 +387,7 @@
         return FUNCTION_SUCCESS;
 }
 
-int Loader_XM::load_instrument_internal(Instrument *p_instr,bool p_xi,int p_cpos, int p_hsize, int p_sampnum=-1) {
+int Loader_XM::load_instrument_internal(Instrument *p_instr,bool p_xi,int p_cpos, int p_hsize, int p_sampnum) {
 
   		int sampnum;
                 Uint32 aux;
@@ -807,7 +807,7 @@
 
 }
 
-void Loader_XM::free_info(bool free_sampledata=false) {
+void Loader_XM::free_info(bool free_sampledata) {
 
   	if (free_sampledata)
 		for (int x=0;x<samples.size();x++) {
