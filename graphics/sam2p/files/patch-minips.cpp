--- minips.cpp.orig	2014-01-19 19:50:35 UTC
+++ minips.cpp
@@ -292,9 +292,9 @@ MiniPS::Real::Real(double d_, char const
 void MiniPS::Real::dump(GenBuffer::Writable &out_, bool dumpPS_force) {
   char buf[64]; /* Imp: should be enough?? */
   if (metric!=0 && (dumpPS_force || dumpPS)) {
-    sprintf(buf, "%"PTS_CFG_PRINTFGLEN"g%s", d, me_psfactor[metric]);
+    sprintf(buf, "%" PTS_CFG_PRINTFGLEN "g%s", d, me_psfactor[metric]);
   } else {
-    sprintf(buf, "%"PTS_CFG_PRINTFGLEN"g", d*me_factor[metric]);
+    sprintf(buf, "%" PTS_CFG_PRINTFGLEN "g", d*me_factor[metric]);
   }
   out_ << buf;
 }
@@ -1044,7 +1044,7 @@ void MiniPS::dumpScale(GenBuffer::Writab
   } else {
     d = d < 0 ? 72.0 / -d : d / 72.0;
     char buf[64]; /* Dat: enough */
-    sprintf(buf, "%"PTS_CFG_PRINTFGLEN"g", d);
+    sprintf(buf, "%" PTS_CFG_PRINTFGLEN "g", d);
     out << buf;
   }
 }
@@ -1093,7 +1093,7 @@ void MiniPS::dumpAdd3(GenBuffer::Writabl
     out << (rounding>=2 && ll<0 ? 0 : ll);
   } else {
     char buf[64]; /* Dat: enough */
-    sprintf(buf, "%"PTS_CFG_PRINTFGLEN"g", d);
+    sprintf(buf, "%" PTS_CFG_PRINTFGLEN "g", d);
     out << buf;
   }
 }
