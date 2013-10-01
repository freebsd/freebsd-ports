--- src/runtime/StatPhase.cc.orig	2011-04-04 22:07:36.000000000 +0000
+++ src/runtime/StatPhase.cc
@@ -413,12 +413,12 @@ void StatPhase::noteXactEvent(BcastChann
 						break;
 				}
 		} else {
-			static CompoundXactInfo &compound = *CompoundXactInfo::Create();
-			compound.exchanges = 1;
-			compound.reqSize = reqSize;
-			compound.repSize = repSize;
-			compound.lifeTime = repTime;
-			compound.record(rec.theIsolated);
+			static CompoundXactInfo &compound2 = *CompoundXactInfo::Create();
+			compound2.exchanges = 1;
+			compound2.reqSize = reqSize;
+			compound2.repSize = repSize;
+			compound2.lifeTime = repTime;
+			compound2.record(rec.theIsolated);
 		}
 
 		if (x->cookiesSent() > 0)
