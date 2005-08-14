--- src/include/vigra_ext/PointMatching.h.orig	Thu Aug 11 19:34:40 2005
+++ src/include/vigra_ext/PointMatching.h	Thu Aug 11 19:48:12 2005
@@ -33,7 +33,9 @@
 
 // BAD: sgi stl extension
 #if defined(__GNUC__)
+#if __GNUC__ > 2
     #include <ext/algorithm>
+#endif
 #elif defined(HAVE_STLport)
     #include <stlport4/algorithm>
 #endif
@@ -193,8 +195,13 @@
         {
             std::vector<SIFTFeature> randomfeat(feat1.size()*m_percent/100);
 #if defined(__GNUC__)
+#if __GNUC__ > 2
             __gnu_cxx::random_sample(feat1.begin(), feat1.end(),
                                randomfeat.begin(), randomfeat.end());
+#else
+	    std::random_sample(feat1.begin(), feat1.end(),
+                          randomfeat.begin(), randomfeat.end());
+#endif
 #elif defined(HAVE_STLport)
             _STL::random_sample(feat1.begin(), feat1.end(),
                                randomfeat.begin(), randomfeat.end());
