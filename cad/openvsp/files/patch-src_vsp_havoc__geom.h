Workaround for libc++, which declares std::array even if not in C++11 mode (see
ports/207253 for a bigger discussion).
--- src/vsp/havoc_geom.h.orig	2016-02-25 10:33:52 UTC
+++ src/vsp/havoc_geom.h
@@ -88,11 +88,11 @@ class Havoc_geom : public Geom
    int havoc_num_xsecs;
    int havoc_num_pnts;
    
-   array< double > x_locs;
-   array< double > left;
-   array< double > right;
-   array< double > upper;
-   array< double > lower;
+   openvsp::array< double > x_locs;
+   openvsp::array< double > left;
+   openvsp::array< double > right;
+   openvsp::array< double > upper;
+   openvsp::array< double > lower;
  
    Parm length;
    
