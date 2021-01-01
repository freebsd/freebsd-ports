--- arangod/RestHandler/RestAuthHandler.cpp.orig	2018-04-06 22:44:29 UTC
+++ arangod/RestHandler/RestAuthHandler.cpp
@@ -54,7 +54,7 @@ std::string RestAuthHandler::generateJwt
     VPackObjectBuilder p(&bodyBuilder);
     bodyBuilder.add("preferred_username", VPackValue(username));
     bodyBuilder.add("iss", VPackValue("arangodb"));
-    bodyBuilder.add("exp", VPackValue(exp.count()));
+    bodyBuilder.add("exp", VPackValue((int64_t)exp.count()));
   }
   AuthenticationFeature* af = AuthenticationFeature::instance();
   TRI_ASSERT(af != nullptr);
