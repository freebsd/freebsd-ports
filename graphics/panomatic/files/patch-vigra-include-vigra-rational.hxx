--- vigra/include/vigra/rational.hxx.orig	2008-02-14 23:14:15.000000000 +0000
+++ vigra/include/vigra/rational.hxx	2012-09-24 12:02:46.539117586 +0000
@@ -1015,6 +1015,7 @@
     // Handle the easy cases. Take advantage of the fact
     // that the denominator is never negative.
     if(l.denominator() == zero)
+    {
         if(r.denominator() == zero)
             // -inf < inf, !(-inf < -inf), !(inf < -inf), !(inf < inf)
             return l.numerator() < r.numerator();
@@ -1022,6 +1023,7 @@
             // -inf < -1, -inf < 0, -inf < 1
             // !(inf < -1), !(inf < 0), !(inf < 1)
             return l.numerator() < zero;
+    }
     if(r.denominator() == zero)
         // -1 < inf, 0 < inf, 1 < inf
         // !(-1 < -inf), !(0 < -inf), !(1 < -inf)
