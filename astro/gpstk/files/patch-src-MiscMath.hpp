--- src/MiscMath.hpp.orig	Thu Jan 11 21:29:49 2007
+++ src/MiscMath.hpp	Thu Jan 11 21:30:37 2007
@@ -145,6 +145,9 @@
       }
    }  // end void LagrangeInterpolation(vector, vector, const T, T&, T&)
 
+   template <class T>
+   T RSS (T aa, T bb, T cc);
+
    /// Perform the root sum square of aa, bb
    template <class T>
    T RSS (T aa, T bb)
