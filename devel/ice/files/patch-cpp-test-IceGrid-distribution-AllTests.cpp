--- cpp/test/IceGrid/distribution/AllTests.cpp.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/IceGrid/distribution/AllTests.cpp
@@ -123,7 +123,7 @@ allTests(const Ice::CommunicatorPtr& communicator)
     {
         ApplicationUpdateDescriptor update;
         update.name = "Test";
-        update.variables["icepatch.directory"] = "${test.dir}/data/updated";
+        update.variables["icepatch.directory"] = "${test.dir}/db/data/updated";
         admin->updateApplication(update);
         
         admin->startServer("Test.IcePatch2");
@@ -212,7 +212,7 @@ allTests(const Ice::CommunicatorPtr& communicator)
         ApplicationDescriptor app = admin->getApplicationInfo("Test").descriptor;
         admin->removeApplication("Test");
         
-        app.variables["icepatch.directory"] = "${test.dir}/data/original";
+        app.variables["icepatch.directory"] = "${test.dir}/db/data/original";
         test(app.nodes["localnode"].servers[2]->id == "server-dir1");
         app.nodes["localnode"].servers[2]->applicationDistrib = false;
         
