--- source/ServerList.C.orig	Sat Nov 23 21:47:22 2002
+++ source/ServerList.C	Sat Nov 23 21:47:47 2002
@@ -40,7 +40,7 @@
 void
 ServerList::delServer(int n)
 {
-  v.erase(&v[n]);
+  v.erase(v.begin() + n);
 }
 
 Server *
