-- Fix NeuralAudio compatibility with newer Eigen by using Eigen::lastN.
-- Eigen::placeholders::lastN is not available in the Eigen version shipped
-- with FreeBSD, which causes the NeuralRack build to fail.

--- NeuralAudio/NeuralAudio/LSTM.h.orig	2026-07-23 18:33:39 UTC
+++ NeuralAudio/NeuralAudio/LSTM.h
@@ -37,7 +37,7 @@ namespace NeuralAudio
 		constexpr static long hOffset = InputSize;
 
 	public:
-		auto GetHiddenState() const { return state(Eigen::placeholders::lastN(HiddenSize)); };
+		auto GetHiddenState() const { return state(Eigen::lastN(HiddenSize)); };
 
 		void SetNAMWeights(std::vector<float>::iterator& weights)
 		{
