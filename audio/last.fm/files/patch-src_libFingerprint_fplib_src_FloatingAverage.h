--- src/libFingerprint/fplib/src/FloatingAverage.h.orig	2016-07-26 15:06:09 UTC
+++ src/libFingerprint/fplib/src/FloatingAverage.h
@@ -78,6 +78,7 @@ public:
    {
       T real_sum = 0;
       const T* pCircularBuffer = m_values.get_buffer();
+      const int size = m_values.size();
       for ( int i = 0; i < size; ++i )
          real_sum += pCircularBuffer[i];
       return abs(real_sum - m_sum) / this->size();
