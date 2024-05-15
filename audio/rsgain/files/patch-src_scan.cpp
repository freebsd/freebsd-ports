Fix a segfault when calculating album loudness.

PR: 278838
Regressed by: https://github.com/complexlogic/rsgain/commit/63e87a4f7d3b5c816eab630fba41ba9a63b82519

--- src/scan.cpp.orig	2024-02-25 17:47:20 UTC
+++ src/scan.cpp
@@ -639,7 +639,7 @@ void ScanJob::calculate_album_loudness() 
     std::vector<ebur128_state*> states(nb_states);
     for (const Track &track : tracks)
         if (track.result.track_loudness != -HUGE_VAL)
-            states.emplace_back(track.ebur128.get());
+            states[(size_t) (&track - &tracks[0])] = track.ebur128.get();
 
     if (ebur128_loudness_global_multiple(states.data(), states.size(), &album_loudness) != EBUR128_SUCCESS)
         album_loudness = config.target_loudness;
