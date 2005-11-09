--- boost/test/impl/test_tools.ipp.orig	Sun Aug 21 14:08:00 2005
+++ boost/test/impl/test_tools.ipp	Sun Aug 21 14:09:41 2005
@@ -173,7 +173,7 @@
         unit_test_log << "difference between " << arg1_descr << "{" << arg1_val << "}" 
                       << " and "               << arg2_descr << "{" << arg2_val << "}"
                       << ( tl == PASS ? " doesn't exceed " : " exceeds " )
-                      << toler_val << "%",
+                      << toler_val << "%";
 
         va_end( args );
         
@@ -196,7 +196,7 @@
 
         unit_test_log << "absolute value of " << arg1_descr << "{" << arg1_val << "}" 
                       << ( tl == PASS ? " doesn't exceed " : " exceeds " )
-                      << toler_val,
+                      << toler_val;
 
         va_end( args );
         
