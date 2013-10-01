--- src/xstd/Ring.h.orig	2011-04-04 22:07:36.000000000 +0000
+++ src/xstd/Ring.h
@@ -22,11 +22,11 @@ class Ring: protected Array<Item> {
 		int size() const { return Array<Item>::size(); }
 		bool empty() const { return this->theInOff <= this->theOutOff; }
 		bool full() const { return count() >= this->theCapacity; }
-		const Item &top(int off = 0) const { return item((this->theOutOff+off) % this->theCapacity); }
+		const Item &top(int off = 0) const { return this->item((this->theOutOff+off) % this->theCapacity); }
 
-		Item &top(int off = 0) { return item((this->theOutOff+off) % this->theCapacity); }
-		void enqueue(Item i) { Assert(!full()); item(this->theInOff++ % this->theCapacity) = i; check(); }
-		Item dequeue() { return item(this->theOutOff++ % this->theCapacity); }
+		Item &top(int off = 0) { return this->item((this->theOutOff+off) % this->theCapacity); }
+		void enqueue(Item i) { Assert(!full()); this->item(this->theInOff++ % this->theCapacity) = i; check(); }
+		Item dequeue() { return this->item(this->theOutOff++ % this->theCapacity); }
 
 		void reset() { this->theInOff = this->theOutOff = 0; }
 		inline void resize(int aCap);
