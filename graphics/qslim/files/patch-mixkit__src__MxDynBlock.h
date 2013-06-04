--- mixkit/src/MxDynBlock.h.orig
+++ mixkit/src/MxDynBlock.h
@@ -35,13 +35,13 @@
 
     void room_for(int len)
     {
-	if( length()<len ) resize(len);
+	if( length()<len ) this->resize(len);
 	fill = len;
     }
 
     T& add()
     {
-	if( length()==total_space() )  resize(total_space() * 2);
+	if( length()==total_space() )  this->resize(total_space() * 2);
 	fill++;
 	return last();
     }
@@ -62,8 +62,8 @@
     //
     int size() const { return length(); }
 
-    typename MxBlock<T>::iterator end()       { return begin()+size(); }
-    typename MxBlock<T>::const_iterator end() const { return begin()+size(); }
+    typename MxBlock<T>::iterator end()       { return this->begin()+size(); }
+    typename MxBlock<T>::const_iterator end() const { return this->begin()+size(); }
 
     void push_back(const T& t) { add(t); }
 };
