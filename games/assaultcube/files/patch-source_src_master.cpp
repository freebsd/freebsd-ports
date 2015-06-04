--- source/src/master.cpp.orig	2013-10-09 08:27:37 UTC
+++ source/src/master.cpp
@@ -510,7 +510,7 @@
     authreq &a = c.authreqs.add();
     a.reqtime = servtime;
     a.id = id;
-    uint seed[3] = { starttime, servtime, randomMT() };
+    uint seed[3] = { (uint)starttime, servtime, randomMT() };
     static vector<char> buf;
     buf.setsize(0);
     a.answer = genchallenge(u->pubkey, seed, sizeof(seed), buf);
