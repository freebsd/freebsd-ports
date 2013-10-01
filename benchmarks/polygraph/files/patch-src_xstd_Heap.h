--- src/xstd/Heap.h.orig	2011-04-04 22:07:36.000000000 +0000
+++ src/xstd/Heap.h
@@ -23,7 +23,7 @@ class Heap: protected Array<Item> {
 		const Item &top() const { return this->theItems[1]; }
 		Item &at(int idx) { return this->theItems[idx+1]; }
 
-		void add(Item v) { append(v); floatUp(++theCnt); }
+		void add(Item v) { this->append(v); floatUp(++theCnt); }
 		void skip() { this->theItems[1] = this->theItems[theCnt--]; this->theCount--; sinkDown(1); }
 		Item shift() { const Item v = this->theItems[1]; skip(); return v; }
 
