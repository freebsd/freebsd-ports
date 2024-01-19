--- src/util/data_structures/deque.h.orig	2023-12-29 18:15:28 UTC
+++ src/util/data_structures/deque.h
@@ -186,6 +186,11 @@ struct Deque {
 			return *this;
 		}
 
+		Iterator& operator-=(ptrdiff_t i) {
+			i_ -= i;
+			return *this;
+		}
+
 	private:
 
 		ptrdiff_t i_;
