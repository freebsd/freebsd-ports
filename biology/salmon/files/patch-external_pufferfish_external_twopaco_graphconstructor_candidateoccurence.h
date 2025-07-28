--- external/pufferfish/external/twopaco/graphconstructor/candidateoccurence.h.orig	2025-07-26 13:01:27 UTC
+++ external/pufferfish/external/twopaco/graphconstructor/candidateoccurence.h
@@ -58,7 +58,7 @@ namespace TwoPaCo
 		const CandidateOccurence & operator = (const CandidateOccurence & toCopy)
 		{
 			body_ = toCopy.body_;
-			count_ = toCopy.count_;
+			count_.store(toCopy.count_.load(std::memory_order_relaxed));
 		}
 
 		void Inc()
