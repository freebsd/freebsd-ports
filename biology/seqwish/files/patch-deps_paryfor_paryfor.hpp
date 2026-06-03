- fix for PPC
- fix build with clang19

--- deps/paryfor/paryfor.hpp.orig 2024-10-15 18:25:21 UTC
+++ deps/paryfor/paryfor.hpp
@@ -51,7 +51,22 @@ static inline void spin_loop_pause() noexcept {
 }
 } // namespace atomic_queue
 } // namespace paryfor
+#elif defined(__ppc64__) || defined(__powerpc64__)
+namespace paryfor {
+namespace atomic_queue {
+constexpr int CACHE_LINE_SIZE = 128; // TODO: Review that this is the correct value.
+static inline void spin_loop_pause() noexcept {
+    asm volatile("or 31,31,31 # very low priority"); // TODO: Review and benchmark that this is the right instruction.
+}
+} // namespace atomic_queue
+} // namespace paryfor
 #else
+namespace paryfor {
+namespace atomic_queue {
+constexpr int CACHE_LINE_SIZE = 64; // TODO: Review that this is the correct value.
+static inline void spin_loop_pause() noexcept {}
+} // namespace atomic_queue
+} // namespace paryfor
 #error "Unknown CPU architecture."
 #endif
 
@@ -453,13 +468,13 @@ class AtomicQueue2 : public AtomicQueueCommon<AtomicQ
 
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
@@ -581,13 +596,13 @@ class AtomicQueue2B : public AtomicQueueCommon<Atomic
 
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
