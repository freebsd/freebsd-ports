--- src/libFingerprint/fplib/src/FloatingAverage.h.orig	2007-12-18 15:18:19.000000000 +0100
+++ src/libFingerprint/fplib/src/FloatingAverage.h	2012-11-25 13:23:10.000000000 +0100
@@ -78,6 +78,7 @@
    {
       T real_sum = 0;
       const T* pCircularBuffer = m_values.get_buffer();
+      const int size = m_values.size();
       for ( int i = 0; i < size; ++i )
          real_sum += pCircularBuffer[i];
       return abs(real_sum - m_sum) / this->size();


