--- ./utils/dgraphics_nosdl.cc.orig	2009-06-10 07:32:20.000000000 +0900
+++ ./utils/dgraphics_nosdl.cc	2009-06-17 18:21:05.000000000 +0900
@@ -40,6 +40,12 @@
         }
     }
 
+    bool dactive() {
+    }
+
+    const char *dsection_set(const char *section) {
+    }
+
     template <class T>
     void dshow(narray<T> &data,const char *spec,double angle,int smooth,int rgb) {
     }
