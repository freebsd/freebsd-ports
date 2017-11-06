--- Configuration.cpp.orig	2017-10-19 22:13:43 UTC
+++ Configuration.cpp
@@ -2681,14 +2681,14 @@ void Configuration::impl::fill_port_comb
 auto Configuration::impl::apply_calibration (Frequency f) const -> Frequency
 {
   if (frequency_calibration_disabled_) return f;
-  return std::llround (calibration_.intercept
+  return llround (calibration_.intercept
                        + (1. + calibration_.slope_ppm / 1.e6) * f);
 }
 
 auto Configuration::impl::remove_calibration (Frequency f) const -> Frequency
 {
   if (frequency_calibration_disabled_) return f;
-  return std::llround ((f - calibration_.intercept)
+  return llround ((f - calibration_.intercept)
                        / (1. + calibration_.slope_ppm / 1.e6));
 }
 
