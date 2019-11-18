--- tools/block_cache_analyzer/block_cache_trace_analyzer.cc.orig	2019-10-30 17:32:00 UTC
+++ tools/block_cache_analyzer/block_cache_trace_analyzer.cc
@@ -580,7 +580,7 @@ void BlockCacheTraceAnalyzer::WriteCorre
     const std::map<std::string, Features>& label_features,
     const std::map<std::string, Predictions>& label_predictions,
     uint32_t max_number_of_values) const {
-  std::default_random_engine rand_engine(env_->NowMicros());
+  std::default_random_engine rand_engine(static_cast<unsigned int>(env_->NowMicros()));
   for (auto const& label_feature_vectors : label_features) {
     const Features& past = label_feature_vectors.second;
     auto it = label_predictions.find(label_feature_vectors.first);
