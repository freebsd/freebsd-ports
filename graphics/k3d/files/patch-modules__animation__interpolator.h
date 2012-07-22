--- modules/animation/interpolator.h.orig	2010-07-03 11:27:55.000000000 +0900
+++ modules/animation/interpolator.h	2012-06-20 16:01:55.000000000 +0900
@@ -92,7 +92,7 @@
 	{
 		time_t t_lower, t_upper;
 		value_t v_lower, v_upper;
-		get_surrounding_keys(Time, Keyframes, t_lower, t_upper, v_lower, v_upper); 
+		this->get_surrounding_keys(Time, Keyframes, t_lower, t_upper, v_lower, v_upper); 
 		return lerp(t_lower, t_upper, v_lower, v_upper, Time);
 	}
 protected:
@@ -116,7 +116,7 @@
 	{
 		time_t t_lower, t_upper;
 		value_t v_lower, v_upper;
-		get_surrounding_keys(Time, Keyframes, t_lower, t_upper, v_lower, v_upper); 
+		this->get_surrounding_keys(Time, Keyframes, t_lower, t_upper, v_lower, v_upper); 
 		return lerp(t_lower, t_upper, v_lower, v_upper, Time);
 	} 
 protected:
