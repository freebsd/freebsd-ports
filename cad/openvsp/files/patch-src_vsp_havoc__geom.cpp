Workaround for libc++, which declares std::array even if not in C++11 mode (see
ports/207253 for a bigger discussion).
--- src/vsp/havoc_geom.cpp.orig	2016-02-25 10:35:42 UTC
+++ src/vsp/havoc_geom.cpp
@@ -428,7 +428,7 @@ void Havoc_geom::generate_planform_curve
   
   //==== Find Xsec Locations ====// 
   int num_xsecs = havoc_num_xsecs - 3;
-  array< double > tmp_x;
+  openvsp::array< double > tmp_x;
   tmp_x.init ( num_xsecs );
   
   for ( i = 0 ; i < num_xsecs ; i++ )
