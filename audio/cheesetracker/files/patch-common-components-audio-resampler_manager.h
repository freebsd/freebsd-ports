--- common/components/audio/resampler_manager.h.orig	Thu Apr 12 00:03:58 2007
+++ common/components/audio/resampler_manager.h	Thu Apr 12 00:04:14 2007
@@ -34,7 +34,7 @@
 
 public:
 
-	static Resampler_Manager * Resampler_Manager::get_resampler_manager();
+	static Resampler_Manager * get_resampler_manager();
 	int get_resampler_count();
 	Resampler * get_resampler(int p_index);
 
