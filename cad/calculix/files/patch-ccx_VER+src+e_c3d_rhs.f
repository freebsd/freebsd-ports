--- ccx_1.1/src/e_c3d_rhs.f.orig	Tue Sep 23 23:17:44 2003
+++ ccx_1.1/src/e_c3d_rhs.f	Tue Sep 23 23:33:14 2003
@@ -226,6 +226,14 @@
 !           body forces
 !
             if(ibod.ne.0) then
+!
+! incorporating the jacobian determinant in the shape
+! functions
+!
+	    do i1=1,nope
+	    shpj(4,i1)=shp(4,i1)*xsj
+	    enddo
+!
                if(om.gt.0.d0) then
                   do i1=1,3
 !
