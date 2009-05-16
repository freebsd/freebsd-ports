--- include/ptlib/critsec.h.orig	2009-04-25 15:01:31.000000000 +0400
+++ include/ptlib/critsec.h	2009-04-25 15:02:45.000000000 +0400
@@ -249,13 +249,13 @@
 __inline PAtomicInteger::IntegerType PAtomicInteger::operator--(int)        { return EXCHANGE_AND_ADD(&m_value, -1); }
 __inline void PAtomicInteger::SetValue(IntegerType value)                   { m_value = value; }
 #else
-__inline PAtomicInteger::PAtomicInteger(IntegerType value) : m_value(value) { pthread_mutex_init(&mutex, NULL); }
-__inline PAtomicInteger::~PAtomicInteger()                                  { pthread_mutex_destroy(&mutex); }
-__inline PAtomicInteger::IntegerType PAtomicInteger::operator++()           { pthread_mutex_lock(&mutex); int retval = ++m_value; pthread_mutex_unlock(&mutex); return retval; }
-__inline PAtomicInteger::IntegerType PAtomicInteger::operator++(int)        { pthread_mutex_lock(&mutex); int retval = m_value++; pthread_mutex_unlock(&mutex); return retval; }
-__inline PAtomicInteger::IntegerType PAtomicInteger::operator--()           { pthread_mutex_lock(&mutex); int retval = --m_value; pthread_mutex_unlock(&mutex); return retval; }
-__inline PAtomicInteger::IntegerType PAtomicInteger::operator--(int)        { pthread_mutex_lock(&mutex); int retval = m_value--; pthread_mutex_unlock(&mutex); return retval; }
-__inline void PAtomicInteger::SetValue(IntegerType v)                       { pthread_mutex_lock(&mutex); m_value = v; pthread_mutex_unlock(&mutex); }
+__inline PAtomicInteger::PAtomicInteger(IntegerType value) : m_value(value) { pthread_mutex_init(&m_mutex, NULL); }
+__inline PAtomicInteger::~PAtomicInteger()                                  { pthread_mutex_destroy(&m_mutex); }
+__inline PAtomicInteger::IntegerType PAtomicInteger::operator++()           { pthread_mutex_lock(&m_mutex); int retval = ++m_value; pthread_mutex_unlock(&m_mutex); return retval; }
+__inline PAtomicInteger::IntegerType PAtomicInteger::operator++(int)        { pthread_mutex_lock(&m_mutex); int retval = m_value++; pthread_mutex_unlock(&m_mutex); return retval; }
+__inline PAtomicInteger::IntegerType PAtomicInteger::operator--()           { pthread_mutex_lock(&m_mutex); int retval = --m_value; pthread_mutex_unlock(&m_mutex); return retval; }
+__inline PAtomicInteger::IntegerType PAtomicInteger::operator--(int)        { pthread_mutex_lock(&m_mutex); int retval = m_value--; pthread_mutex_unlock(&m_mutex); return retval; }
+__inline void PAtomicInteger::SetValue(IntegerType v)                       { pthread_mutex_lock(&m_mutex); m_value = v; pthread_mutex_unlock(&m_mutex); }
 #endif
 
 
