--- svxlink/trx/SwDtmfDecoder.cpp.orig	2014-04-09 23:44:56.000000000 -0700
+++ svxlink/trx/SwDtmfDecoder.cpp	2014-04-09 23:47:28.000000000 -0700
@@ -175,14 +175,14 @@
   {
     int cfg_fwd_twist = atoi(value.c_str());
     if (cfg_fwd_twist >= 0)
-      normal_twist = exp10f(cfg_fwd_twist/10.0f);
+      normal_twist = powf(10,cfg_fwd_twist/10.0f);
   }
   
   if (cfg().getValue(name(), "DTMF_MAX_REV_TWIST", value))
   {
     int cfg_rev_twist = atoi(value.c_str());
     if (cfg_rev_twist >= 0)
-      reverse_twist = exp10f(cfg_rev_twist/10.0f);
+      reverse_twist = powf(10,cfg_rev_twist/10.0f);
   }
   
   return true;
