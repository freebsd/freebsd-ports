--- source/vdrift/cartire.cpp.orig	2019-03-16 14:58:09 UTC
+++ source/vdrift/cartire.cpp
@@ -280,7 +280,7 @@ Dbl CARTIRE::Pacejka_Fx (Dbl sigma, Dbl Fz, Dbl fricti
 
 	maxforce_output = D;
 
-	assert(!std::isnan(Fx));
+	assert(!isnan(Fx));
 	return Fx;
 }
 
