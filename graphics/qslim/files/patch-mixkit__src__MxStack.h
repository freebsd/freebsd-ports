--- mixkit/src/MxStack.h.orig
+++ mixkit/src/MxStack.h
@@ -26,14 +26,14 @@
     MxStack(const T& val, unsigned int n) : MxDynBlock<T>(n)
 	{ push(val); }
 
-    T&       top()       { return last(); }
-    const T& top() const { return last(); }
+    T&       top()       { return this->last(); }
+    const T& top() const { return this->last(); }
 
-    bool is_empty() { return length()==0; }
+    bool is_empty() { return this->length()==0; }
 
-    T& pop() { return drop(); }
+    T& pop() { return this->drop(); }
 
-    void push(const T& val) { add(val); }
+    void push(const T& val) { this->add(val); }
     //
     // NOTE: In this code, it is *crucial* that we do the add() and
     //       assignment in separate steps.  The obvious alternative
@@ -41,7 +41,7 @@
     //       broken!  The top() will grab a pointer into the block,
     //       but the add() may reallocate the block before doing the
     //       assignment.  Thus, the pointer will become invalid.
-    void push() { add(); top() = (*this)[length()-2]; }
+    void push() { this->add(); top() = (*this)[this->length()-2]; }
 };
 
 // MXSTACK_INCLUDED
