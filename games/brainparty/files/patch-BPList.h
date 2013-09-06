--- BPList.h.orig	2010-03-02 16:29:45.000000000 +0300
+++ BPList.h	2013-09-06 22:05:04.125227873 +0400
@@ -138,7 +138,7 @@
 	~BPPList();
 	void Add(T item);
 	bool Contains(T item);
-	void Clear(bool safe_delete);
+	void Clear(bool safe_delete = true);
 	int IndexOf(T item);
 	void Insert(int pos, T item);
 	void Remove(T item);
@@ -171,7 +171,7 @@
 }
 
 template <class T>
-void BPPList<T>::Clear(bool safe_delete = true) {
+void BPPList<T>::Clear(bool safe_delete) {
 	if (safe_delete) {
 		for (int i = data.size() - 1; i >= 0; --i) {
 			T item = data[i];
