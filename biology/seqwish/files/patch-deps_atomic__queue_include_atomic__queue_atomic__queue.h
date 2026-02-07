- fix compilation error with clang-19

--- deps/atomic_queue/include/atomic_queue/atomic_queue.h.orig	2025-10-10 06:48:58.627210000 -0700
+++ deps/atomic_queue/include/atomic_queue/atomic_queue.h	2025-10-10 06:49:07.323108000 -0700
@@ -393,13 +393,13 @@
 
     T do_pop(unsigned tail) noexcept {
         unsigned index = details::remap_index<SHUFFLE_BITS>(tail % size_);
-        return Base::template do_pop_any(states_[index], elements_[index]);
+        return Base::template do_pop_any<>(states_[index], elements_[index]);
     }
 
     template<class U>
     void do_push(U&& element, unsigned head) noexcept {
         unsigned index = details::remap_index<SHUFFLE_BITS>(head % size_);
-        Base::template do_push_any(std::forward<U>(element), states_[index], elements_[index]);
+        Base::template do_push_any<>(std::forward<U>(element), states_[index], elements_[index]);
     }
 
 public:
@@ -521,13 +521,13 @@
 
     T do_pop(unsigned tail) noexcept {
         unsigned index = details::remap_index<SHUFFLE_BITS>(tail & (size_ - 1));
-        return Base::template do_pop_any(states_[index], elements_[index]);
+        return Base::template do_pop_any<>(states_[index], elements_[index]);
     }
 
     template<class U>
     void do_push(U&& element, unsigned head) noexcept {
         unsigned index = details::remap_index<SHUFFLE_BITS>(head & (size_ - 1));
-        Base::template do_push_any(std::forward<U>(element), states_[index], elements_[index]);
+        Base::template do_push_any<>(std::forward<U>(element), states_[index], elements_[index]);
     }
 
 public:
