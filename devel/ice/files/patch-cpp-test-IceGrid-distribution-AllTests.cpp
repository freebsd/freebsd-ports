--- cpp/test/IceGrid/distribution/AllTests.cpp.orig	2015-07-04 13:40:02.746382995 +0200
+++ cpp/test/IceGrid/distribution/AllTests.cpp	2015-07-04 13:40:20.588960995 +0200
@@ -123,7 +123,7 @@
     {
         ApplicationUpdateDescriptor update;
         update.name = "Test";
-        update.variables["icepatch.directory"] = "${test.dir}/data/updated";
+        update.variables["icepatch.directory"] = "${test.dir}/db/data/updated";
         admin->updateApplication(update);
         
         admin->startServer("Test.IcePatch2");
@@ -212,7 +212,7 @@
         ApplicationDescriptor app = admin->getApplicationInfo("Test").descriptor;
         admin->removeApplication("Test");
         
-        app.variables["icepatch.directory"] = "${test.dir}/data/original";
+        app.variables["icepatch.directory"] = "${test.dir}/db/data/original";
         test(app.nodes["localnode"].servers[2]->id == "server-dir1");
         app.nodes["localnode"].servers[2]->applicationDistrib = false;
         
