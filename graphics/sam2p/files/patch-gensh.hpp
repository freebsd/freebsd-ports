--- gensi.hpp.orig	2008-05-27 03:58:43.000000000 +0900
+++ gensi.hpp	2010-03-19 05:53:15.000000000 +0900
@@ -252,7 +252,7 @@
       if (len!=0) block(beg,len,data);
       block(0,0,data);
     }
-    inline virtual void first_sub(Sub &sub) const { sub.beg=beg; sub.len=len; };
+    inline virtual void first_sub(Sub &sub) const { sub.beg=beg; sub.len=len; }
     inline virtual void next_sub(Sub &sub) const { sub.len=0; }
     inline char const*getCString() const { return beg; }
     inline char const*operator()() const { return beg; }
