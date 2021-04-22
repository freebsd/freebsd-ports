https://github.com/spring/CircuitAI/pull/17/files

--- AI/Skirmish/CircuitAI/src/circuit/module/EconomyManager.h.orig	2021-01-01 16:10:55 UTC
+++ AI/Skirmish/CircuitAI/src/circuit/module/EconomyManager.h
@@ -164,7 +164,7 @@ class CEconomyManager: public IModule { (private)
 		float pull;
 		int mex;
 		float fraction;
-		inline bool operator< (const SPullMtoS& rhs) { return mex < rhs.mex; }
+		inline bool operator< (const SPullMtoS& rhs) const { return mex < rhs.mex; }
 		inline bool operator() (const SPullMtoS& lhs, const int rhs) { return lhs.mex < rhs; }
 	};
 	std::vector<SPullMtoS> mspInfos;
