--- sql/locks/shared_spin_lock.cc.orig	2023-06-05 20:41:14 UTC
+++ sql/locks/shared_spin_lock.cc
@@ -239,7 +239,7 @@ lock::Shared_spin_lock &lock::Shared_spin_lock::try_or
   {
     this->spin_exclusive_lock();
   }
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
   my_atomic_store64(&this->m_exclusive_owner, reinterpret_cast<int64>(self));
 #else
   my_atomic_store64(&this->m_exclusive_owner, self);
