--- ccx_1.0/src/profil.f.orig	Sun Jun 22 00:32:56 2003
+++ ccx_1.0/src/profil.f	Sun Jun 22 00:38:14 2003
@@ -31,6 +31,7 @@
       do 20 i=1,n
          jstrt=xadj(i)
          jstop=xadj(i+1)-1
+         if(jstrt.gt.jstop) cycle
          oldmin=adj(jstrt)
          newmin=nnn(adj(jstrt))
 !
