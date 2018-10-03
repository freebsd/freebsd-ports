--- in_ps.cpp.orig	2014-01-19 19:50:35 UTC
+++ in_ps.cpp
@@ -137,7 +137,7 @@ static Image::Sampled *in_eps_reader(Ima
     // fprintf(stderr, "bbox=[%"PTS_CFG_PRINTFGLEN"g %"PTS_CFG_PRINTFGLEN"g %"PTS_CFG_PRINTFGLEN"g %"PTS_CFG_PRINTFGLEN"g]\n", llx, lly, urx, ury);
     /* Dat: we must call translate _after_ setpagedevice (so it will take effect), at least with ESP Ghostscript 7.05.6 (2003-02-05); BUGFIX at Fri Aug 12 22:49:07 CEST 2005 */
     sprintf(bboxline,
-      "<</PageSize[%"PTS_CFG_PRINTFGLEN"g %"PTS_CFG_PRINTFGLEN"g]>>setpagedevice\n"
+      "<</PageSize[%" PTS_CFG_PRINTFGLEN "g %" PTS_CFG_PRINTFGLEN "g]>>setpagedevice\n"
       /* removing /PageSize also cancels /a4, /a5 etc. */
       /* we need `currentmatrix ... setpagedevice setmatrix' because
        * setpagedevice cancels the current transformation matrix so our
@@ -147,7 +147,7 @@ static Image::Sampled *in_eps_reader(Ima
       "/setpagedevice{matrix currentmatrix exch "
       "dup length dict copy dup /PageSize undef setpagedevice "
       "setmatrix}bind def\n"
-      "%"PTS_CFG_PRINTFGLEN"g %"PTS_CFG_PRINTFGLEN"g translate\n"
+      "%" PTS_CFG_PRINTFGLEN "g %" PTS_CFG_PRINTFGLEN "g translate\n"
       , urx-llx, ury-lly, -llx, -lly);
   } else {
     Error::sev(Error::WARNING) << "in_eps_reader: missing EPS bbox" << (Error*)0;
