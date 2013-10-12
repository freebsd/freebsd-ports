--- source/src/master.cpp.orig	2013-10-09 12:27:37.000000000 +0400
+++ source/src/master.cpp	2013-10-11 02:26:24.000000000 +0400
@@ -510,7 +510,7 @@
     authreq &a = c.authreqs.add();
     a.reqtime = servtime;
     a.id = id;
-    uint seed[3] = { starttime, servtime, randomMT() };
+    uint seed[3] = { (uint)starttime, servtime, randomMT() };
     static vector<char> buf;
     buf.setsize(0);
     a.answer = genchallenge(u->pubkey, seed, sizeof(seed), buf);
