--- bardecode/code25i.hh.orig	2019-01-28 12:12:58 UTC
+++ bardecode/code25i.hh
@@ -31,11 +31,11 @@ namespace BarDecode
         static const int END_SEQUENCE = 0xD;
         static const char no_entry = 0;
 
-        static const double n_lq = 15;
-        static const double n_hq = 5.3;
-        static const double w_lq = 5.2;
-        static const double w_hq = 1.5;
-        static const double tol = 0.2;
+        static constexpr const double n_lq = 15;
+        static constexpr const double n_hq = 5.3;
+        static constexpr const double w_lq = 5.2;
+        static constexpr const double w_hq = 1.5;
+        static constexpr const double tol = 0.2;
 
         static const usize_t min_quiet_usize = 5;
         //static const usize_t min_quiet_usize = 10;
