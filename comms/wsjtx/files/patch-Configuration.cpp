--- Configuration.cpp.orig	2017-01-05 15:57:44 UTC
+++ Configuration.cpp
@@ -2548,13 +2548,13 @@ void Configuration::impl::fill_port_comb
 
 auto Configuration::impl::apply_calibration (Frequency f) const -> Frequency
 {
-  return std::llround (frequency_calibration_intercept_
+  return llround (frequency_calibration_intercept_
                        + (1. + frequency_calibration_slope_ppm_ / 1.e6) * f);
 }
 
 auto Configuration::impl::remove_calibration (Frequency f) const -> Frequency
 {
-  return std::llround ((f - frequency_calibration_intercept_)
+  return llround ((f - frequency_calibration_intercept_)
                        / (1. + frequency_calibration_slope_ppm_ / 1.e6));
 }
 
