$NetBSD: patch-src_fingerprint_fplib_FloatingAverage.h,v 1.1 2012/04/17 17:39:47 joerg Exp $

--- src/fingerprint/fplib/FloatingAverage.h.orig	2012-04-17 15:10:50.000000000 +0000
+++ src/fingerprint/fplib/FloatingAverage.h
@@ -76,7 +76,7 @@ public:
    {
       T real_sum = 0;
       const T* pCircularBuffer = m_values.get_buffer();
-      for ( int i = 0; i < size; ++i )
+      for ( int i = 0; i < size(); ++i )
          real_sum += pCircularBuffer[i];
       return abs(real_sum - m_sum) / this->size();
    }
