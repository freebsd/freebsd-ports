--- lib/python/seqbase_iter.cc.orig	Mon Apr 16 12:53:23 2001
+++ lib/python/seqbase_iter.cc	Thu Nov 30 22:09:39 2006
@@ -61,7 +61,7 @@
          return seqref<T>(*seq, count + i);
       }
 
-   template<class T>
+   template<class T> typename
       SeqBase<T>::iterator&  SeqBase<T>::iterator::operator=(const iterator& other) {
          if (this == &other) return *this;
          seq = other.seq;
@@ -69,23 +69,23 @@
          return *this;
       }
 
-   template<class T>
+   template<class T> typename
       SeqBase<T>::iterator  SeqBase<T>::iterator::operator+(int n) const {
          return iterator(seq, count + n);
       }
 
-   template<class T>
+   template<class T> typename
       SeqBase<T>::iterator  SeqBase<T>::iterator::operator-(int n) const {
          return iterator(seq, count - n);
       }
 
-   template<class T>
+   template<class T> typename
       SeqBase<T>::iterator&  SeqBase<T>::iterator::operator+=(int n) {
          count = count + n;
          return *this;
       }
 
-   template<class T>
+   template<class T> typename
       SeqBase<T>::iterator&  SeqBase<T>::iterator::operator-=(int n) {
          count = count - n;
          return *this;
@@ -99,16 +99,16 @@
       }
 
    // prefix ++
-   template<class T>
+   template<class T> typename
       SeqBase<T>::iterator&  SeqBase<T>::iterator::operator++ () { count++; return *this;}
    // postfix ++
-   template<class T>
+   template<class T> typename
       SeqBase<T>::iterator  SeqBase<T>::iterator::operator++ (int) { return iterator(seq, count++);}
    // prefix --
-   template<class T>
+   template<class T> typename
       SeqBase<T>::iterator&  SeqBase<T>::iterator::operator-- () { count--; return *this;}
    // postfix --
-   template<class T>
+   template<class T> typename
       SeqBase<T>::iterator SeqBase<T>::iterator::operator-- (int) { return iterator(seq, count--);}
 
    template<class T>
