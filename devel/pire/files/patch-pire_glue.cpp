--- pire/glue.cpp.orig	2010-11-16 23:42:09.000000000 +0000
+++ pire/glue.cpp
@@ -60,7 +60,7 @@ public:
 		size_t finalTableSize = 0;
 		for (typename yvector<State>::const_iterator i = states.begin(), ie = states.end(); i != ie; ++i)
 			finalTableSize += RangeLen(Lhs().AcceptedRegexps(i->first)) + RangeLen(Rhs().AcceptedRegexps(i->second));
-		SetSc(new Scanner);
+		this->SetSc(new Scanner);
 		Sc().Init(states.size(), Letters(), finalTableSize, size_t(0), Lhs().RegexpsCount() + Rhs().RegexpsCount());
 				
 		for (size_t state = 0; state != states.size(); ++state) {
