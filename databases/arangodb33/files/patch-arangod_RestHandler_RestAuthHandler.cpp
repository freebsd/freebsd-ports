--- arangod/RestHandler/RestAuthHandler.cpp.orig	2017-11-15 11:23:07 UTC
+++ arangod/RestHandler/RestAuthHandler.cpp
@@ -59,7 +59,7 @@ std::string RestAuthHandler::generateJwt
     VPackObjectBuilder p(&bodyBuilder);
     bodyBuilder.add("preferred_username", VPackValue(username));
     bodyBuilder.add("iss", VPackValue("arangodb"));
-    bodyBuilder.add("exp", VPackValue(exp.count()));
+    bodyBuilder.add("exp", VPackValue((int64_t)exp.count()));
   }
   return authentication->authInfo()->generateJwt(bodyBuilder);
 }
