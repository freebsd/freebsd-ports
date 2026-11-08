-- Fix NeuralAudio compatibility with newer Eigen by using Eigen::lastN.
-- Eigen::placeholders::lastN is not available in the Eigen version shipped
-- with FreeBSD, which causes the NeuralRack build to fail.

--- NeuralAudio/NeuralAudio/LSTMDynamic.h.orig	2026-07-23 18:33:39 UTC
+++ NeuralAudio/NeuralAudio/LSTMDynamic.h
@@ -45,7 +45,7 @@ namespace NeuralAudio
 		{
 		}
 
-		auto GetHiddenState() const { return state(Eigen::placeholders::lastN(hiddenSize)); };
+		auto GetHiddenState() const { return state(Eigen::lastN(hiddenSize)); };
 
 		void SetNAMWeights(std::vector<float>::iterator& weights)
 		{
