--- lib/python/seqbase_const_iter.cc.orig	Mon Apr 16 12:53:23 2001
+++ lib/python/seqbase_const_iter.cc	Thu Nov 30 22:11:19 2006
@@ -61,7 +61,7 @@
       return seq->getItem(count + i);
    }
 
-   template<class T>
+   template<class T> typename
    SeqBase<T>::const_iterator::const_iterator& SeqBase<T>::const_iterator::operator=(const const_iterator& other) {
       if (this == &other) return *this;
       seq = other.seq;
@@ -69,23 +69,23 @@
       return *this;
    }
 
-   template<class T>
+   template<class T> typename
    SeqBase<T>::const_iterator::const_iterator SeqBase<T>::const_iterator::operator+(int n) const {
       return const_iterator(seq, count + n);
    }
 
-   template<class T>
+   template<class T> typename
    SeqBase<T>::const_iterator::const_iterator SeqBase<T>::const_iterator::operator-(int n) const {
       return const_iterator(seq, count - n);
    }
 
-   template<class T>
+   template<class T> typename
    SeqBase<T>::const_iterator::const_iterator& SeqBase<T>::const_iterator::operator+=(int n) {
       count = count + n;
       return *this;
    }
 
-   template<class T>
+   template<class T> typename
   SeqBase<T>::const_iterator::const_iterator& SeqBase<T>::const_iterator::operator-=(int n) {
       count = count - n;
       return *this;
@@ -98,16 +98,16 @@
       return count - other.count;
    }
    // prefix ++
-   template<class T>
+   template<class T> typename
    SeqBase<T>::const_iterator::const_iterator& SeqBase<T>::const_iterator::operator++ () { count++; return *this;}
    // postfix ++
-   template<class T>
+   template<class T> typename
    SeqBase<T>::const_iterator::const_iterator SeqBase<T>::const_iterator::operator++ (int) { return const_iterator(seq, count++);}
    // prefix --
-   template<class T>
+   template<class T> typename
    SeqBase<T>::const_iterator::const_iterator& SeqBase<T>::const_iterator::operator-- () { count--; return *this;}
    // postfix --
-   template<class T>
+   template<class T> typename
    SeqBase<T>::const_iterator::const_iterator SeqBase<T>::const_iterator::operator-- (int) { return const_iterator(seq, count--);}
 
 }
