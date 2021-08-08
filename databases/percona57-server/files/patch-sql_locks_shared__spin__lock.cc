--- sql/locks/shared_spin_lock.cc.orig 2021-05-20 11:22:55 UTC
+++ sql/locks/shared_spin_lock.cc
@@ -242,7 +242,7 @@ lock::Shared_spin_lock &lock::Shared_spin_lock::try_or
 #if defined(__APPLE__)
   my_atomic_store64(&this->m_exclusive_owner, reinterpret_cast<int64>(self));
 #else
-  my_atomic_store64(&this->m_exclusive_owner, self);
+  my_atomic_store64(&this->m_exclusive_owner, reinterpret_cast<int64>(self));
 #endif
   return (*this);
 }
