--- net/third_party/quiche/src/quiche/quic/core/quic_interval_deque.h.orig	2024-06-13 07:42:15 UTC
+++ net/third_party/quiche/src/quiche/quic/core/quic_interval_deque.h
@@ -198,12 +198,12 @@ class QUICHE_NO_EXPORT QuicIntervalDeque {
     Iterator operator+(difference_type amount) const {
       Iterator copy = *this;
       copy.index_ += amount;
-      QUICHE_DCHECK(copy.index_ < copy.deque_->size());
+      QUICHE_DCHECK(copy.index_ < copy.deque_->Size());
       return copy;
     }
     Iterator& operator+=(difference_type amount) {
       index_ += amount;
-      QUICHE_DCHECK(index_ < deque_->size());
+      QUICHE_DCHECK(index_ < deque_->Size());
       return *this;
     }
     difference_type operator-(const Iterator& rhs) const {
