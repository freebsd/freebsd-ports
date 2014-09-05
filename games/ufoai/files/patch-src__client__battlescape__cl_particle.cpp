--- ./src/client/battlescape/cl_particle.cpp.orig	2014-06-05 06:18:39.000000000 +0200
+++ ./src/client/battlescape/cl_particle.cpp	2014-08-07 16:49:53.693302810 +0200
@@ -138,7 +138,7 @@
 CASSERT(lengthof(pc_strings) == PC_NUM_PTLCMDS);
 
 /** @brief particle commands parameter and types */
-static const int pc_types[PC_NUM_PTLCMDS] = {
+static const unsigned int pc_types[PC_NUM_PTLCMDS] = {
 	0,
 
 	V_UNTYPED, V_UNTYPED, V_UNTYPED,
