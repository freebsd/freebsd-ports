--- lib/python/seqbase_iter.cc.orig	2001-04-16 21:53:23.000000000 +0200
+++ lib/python/seqbase_iter.cc	2007-11-03 16:39:31.000000000 +0100
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
@@ -99,21 +99,22 @@
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
       std::string  SeqBase<T>::iterator::diagnose() const {
-         std::ostrstream oss;
+         std::ostringstream oss;
+         //std::ostrstream oss;
          oss << "iterator diagnosis " << seq << ", " << count << std::ends;
          return std::string(oss.str());
       }
