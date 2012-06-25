--- svxlink/trx/LocalRx.cpp.orig	2012-06-24 10:40:14.000000000 -0700
+++ svxlink/trx/LocalRx.cpp	2012-06-24 10:40:33.000000000 -0700
@@ -448,15 +448,17 @@
   {
     squelch_det = new SquelchSigLev(siglevdet);
   }
+#if 0
   else if (sql_det_str == "EVDEV")
   {
     squelch_det = new SquelchEvDev;
   }
+#endif
   else
   {
     cerr << "*** ERROR: Unknown squelch type specified in config variable "
       	 << name() << "/SQL_DET. Legal values are: VOX, CTCSS, SIGLEV, "
-	 << "EVDEV and SERIAL\n";
+	 << "and SERIAL\n";
     // FIXME: Cleanup
     return false;
   }
